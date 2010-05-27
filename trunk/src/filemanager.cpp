// Last modified: 2010-05-27 22:25:21 henryhu

#include "filemanager.h"
#include "config.h"
#include "intercmd.h"
#include <string>
#include <iostream>
#include "netmgr.h"
#include "datahasher.h"
using namespace std;

void FileManager::parseFindFileByName(Packet *pkt)
{
	// Packet Format:
	// DWord ID
	// String pattern

	PRInt32 id = pkt->fetchInt();
	string pattern = pkt->fetchStr();

	LogMsg(LOG_EXTEND, "find by name, id: %d, pattern: %s\n", id,
			pattern.c_str());

	PRInt16 rtype = INT_CMD_FIND_FILE_BY_NAME_REPLY;
	Packet *rpkt = new Packet(pkt->getRAddr(), rtype, 500, INTERCONNECT_PORT);
	rpkt->appendInt(id);
	lockFiles();
	for (list<File*>::iterator it = files.begin();
			it != files.end(); it++)
	{
		File *file = *it;
		if (file->matchName(pattern))
		{
			LogMsg(LOG_EXTEND, "matched.\n");
			rpkt->appendByte(1);
			rpkt->appendStr(file->getName());
			rpkt->appendStr(file->getHash().toStr());
			rpkt->appendQWord(file->getLength());
		}
	}
	unlockFiles();
	rpkt->appendByte(0);
	core->getNetMgr()->sendMsg(rpkt, rtype);
}

void FileManager::parseGetFileInformation(Packet *pkt)
{
	// Packet format:
	// String fileName
	// String hash
	// QWord length
	//
	
	string fileName = pkt->fetchStr();
	DataHash hash(pkt->fetchStr());
	PRInt64 length = pkt->fetchQWord();

	PRInt16 rtype = INT_CMD_GET_FILE_INFO_REPLY;
	File *file = findFile(hash, length);
	if ((file == NULL) || (file->getStage() < FILE_STAGE_INFO))
	{
		Packet *rpkt = new Packet(pkt->getRAddr(), rtype, 100, INTERCONNECT_PORT);
		rpkt->appendByte(GET_FILE_INFO_FAILED);
		core->getNetMgr()->sendMsg(rpkt, rtype);
		return;
	}

	Packet *rpkt = new Packet(pkt->getRAddr(), rtype, 500, INTERCONNECT_PORT);
	Block *block = file->getBlocks();
	rpkt->appendByte(GET_FILE_INFO_SUCC);
	rpkt->appendStr(file->getName());
	rpkt->appendStr(file->getHash().toStr());
	rpkt->appendQWord(file->getLength());
	while (block != NULL)
	{
		rpkt->appendByte(1);
		rpkt->appendStr(block->getHash().toStr());
		block = block->getNext();
	}
	rpkt->appendByte(0);

	core->getNetMgr()->sendMsg(rpkt, rtype);
}

void FileManager::parseGetFileInfoReply(Packet *pkt)
{
	// Packet format:
	// Byte result = FAILED / SUCC
	// String fileName
	// String hash
	// QWord length
	// [
	//	Byte itemType = 1
	//	String blockHash
	// ]
	// Byte itemEnd = 0
	
	int res = pkt->fetchByte();
	switch(res)
	{
		case GET_FILE_INFO_FAILED:
			break;
		case GET_FILE_INFO_SUCC:
			string fileName = pkt->fetchStr();
			DataHash hash(pkt->fetchStr());
			PRInt64 length = pkt->fetchQWord();
			File *file = findFile(hash, length);
			if (file == NULL)
			{
				LogMsg(LOG_DEBUG, "received file info while the file cannot be found.\n");
				break;
			}
			file->lock();
			if (file->getStage() > FILE_STAGE_INFO)
			{
				LogMsg(LOG_DEBUG, "file info already received.\n");
				file->unlock();
				break;
			}
			Block *lastBlock = NULL;
			lockBlocks();
			while (pkt->fetchByte() == 1)
			{
				DataHash blockHash(pkt->fetchStr());
				LogMsg(LOG_EXTEND, "block hash: %s\n", 
						blockHash.toStr().c_str());
				Block *block = new Block(blockHash);
				if (lastBlock == NULL)
				{
					file->setFirstBlock(block);
				} else {
					lastBlock->setNextBlock(block);
				}
				addHashBlock(block);
				lastBlock = block;
			}
			unlockBlocks();
			file->unlock();
			break;
	}
}

void FileManager::addHashBlock(Block *b)
{
	b->setHashNext(blocks[b->getHash()]);
	blocks[b->getHash()] = b;
}

FileManager::FileManager(Core *c)
	: core(c)
{
	blockLock = PR_NewLock();
	fileLock = PR_NewLock();
}

File *FileManager::findFile(const DataHash &hash, PRInt64 length)
{
	File *file = hashFiles[hash];
	while (file != NULL)
	{
		if (file->getLength() == length)
			return file;
		file = file->getHashNext();
	}
	return NULL;
}

int FileManager::addLocalFile(const string& path)
{
	LogMsg(LOG_INFO, "adding file: %s\n", path.c_str());
	PRFileDesc *handle = PR_Open(path.c_str(), PR_RDONLY, 0);
	if (handle == NULL)
	{
		LogMsg(LOG_WARN, "cannot open local file for read: %s\n", 
				path.c_str());
		ShowPRError();
		return PR_FAILURE;
	}

	PRFileInfo64 info;
	PRStatus ret = PR_GetOpenFileInfo64(handle, &info);
	if (ret == PR_FAILURE)
	{
		LogMsg(LOG_WARN, "cannot get info of the file: %s\n",
				path.c_str());
		PR_Close(handle);
		return PR_FAILURE;
	}

	if (info.type == PR_FILE_DIRECTORY)
	{
		LogMsg(LOG_WARN, "cannot add directory as file!\n");
		PR_Close(handle);
		return PR_FAILURE;
	}

	int base = -1;
	for (int i=path.length()-1; i>=0; i--)
		if (path[i] == '/')
		{
			base = i;
			break;
		}

	string filename;
	if (base == -1)
		filename = path;
	else
		filename = path.substr(base+1);

	char *buf = new char[BLOCK_SIZE];
	bool finished = false;
	DataHasher hasher;
	Block *lastBlock = NULL;
	File *file = new File(filename, info.size);
	lockBlocks();
	do
	{
		int len = PR_Read(handle, buf, BLOCK_SIZE);

		if (len == -1)
		{
			LogMsg(LOG_WARN, "failed to read local file: %s\n",
					path.c_str());
			ShowPRError();
			PR_Close(handle);
			delete []buf;
			return PR_GetOSError();
		}

		if (len < BLOCK_SIZE)
		{
			if (len == 0) break;
			for (int i=len; i<BLOCK_SIZE; i++)
				buf[i] = 0;

			finished = true;
		}
		hasher.newBlock(buf, BLOCK_SIZE);

		Block *block = new Block(hasher.getCurrent());
		if (lastBlock == NULL)
		{
			file->setFirstBlock(block);
		} else {
			lastBlock->setNextBlock(block);
		}

		lastBlock = block;
		addHashBlock(block);
	} while (!finished);
	file->setHash(hasher.getAll());
	file->setStage(FILE_STAGE_FINISHED);
	addFile(file);
	unlockBlocks();

	delete []buf;
	return PR_SUCCESS;
}

void FileManager::lockBlocks()
{
	PR_Lock(blockLock);
}

void FileManager::unlockBlocks()
{
	PR_Unlock(blockLock);
}

FileManager::~FileManager()
{
	PR_DestroyLock(blockLock);
	blockLock = NULL;
	PR_DestroyLock(fileLock);
	fileLock = NULL;
}

void FileManager::addFile(File *f)
{
	LogMsg(LOG_EXTEND, "adding file.\n");
	lockFiles();
	files.push_back(f);
	File *link = hashFiles[f->getHash()];
	f->setHashNext(link);
	hashFiles[f->getHash()] = f;
	unlockFiles();
}

int FileManager::addLocalDir(const string& path)
{
	LogMsg(LOG_INFO, "adding directory: %s\n", path.c_str());
	PRFileInfo info;
	PR_GetFileInfo(path.c_str(), &info);
	if (info.type != PR_FILE_DIRECTORY)
		LogMsg(LOG_WARN, "cannot add %s as directory!\n", path.c_str());

	PRDir *dir = PR_OpenDir(path.c_str());
	if (dir == NULL)
	{
		LogMsg(LOG_WARN, "open %s as directory failed.\n", path.c_str());
		ShowPRError();
		return PR_FAILURE;
	}

	PRDirEntry *entry;
	while ((entry = 
				PR_ReadDir(dir, PRDirFlags(PR_SKIP_BOTH | PR_SKIP_HIDDEN))) != NULL)
	{
		PR_GetFileInfo((path + "/" + entry->name).c_str(), &info);
		if (info.type == PR_FILE_FILE)
			addLocalFile(path + "/" + entry->name);
		else if (info.type == PR_FILE_DIRECTORY)
			addLocalDir(path + "/" + entry->name);
		else
		{
			LogMsg(LOG_WARN, "unknown entry type: %s\n", (path + "/" +
						entry->name).c_str());
		}
	}

	PR_CloseDir(dir);
	return PR_SUCCESS;
}

void FileManager::lockFiles()
{
	PR_Lock(fileLock);
}

void FileManager::unlockFiles()
{
	PR_Unlock(fileLock);
}

void FileManager::sendGetFileInfo(
		const PRNetAddr &receiver, const string& fileName, 
		const DataHash& hash, PRInt64 length)
{
	PRInt16 type = INT_CMD_GET_FILE_INFO;
	Packet *pkt = new Packet(receiver, type, 100, INTERCONNECT_PORT);
	pkt->appendStr(fileName);
	pkt->appendStr(hash.toStr());
	pkt->appendQWord(length);
	core->getNetMgr()->sendMsg(pkt, type);
}


// Last modified: 2010-05-27 22:25:08 henryhu

#ifndef __DFTS_FILEMANAGER_H_
#define __DFTS_FILEMANAGER_H_

#include <prio.h>
#include "core.h"
#include "packet.h"
#include <list>
#include "file.h"
#include <map>

class Core;

class FileManager {
private:
	Core *core;
	std::list<File *> files;
	std::map<DataHash, Block *> blocks;
	std::map<DataHash, File *> hashFiles;
	PRLock *blockLock;
	PRLock *fileLock;

public:
	void parseGetFileInformation(Packet *pkt);
	void parseGetFileInfoReply(Packet *pkt);
	FileManager(Core *c);
	File *findFile(const DataHash &hash, PRInt64 length);
	void addHashBlock(Block *b);
	int addLocalFile(const std::string& path);
	void lockBlocks();
	void unlockBlocks();
	virtual ~FileManager();
	void addFile(File *f);
	void lockFiles();
	void unlockFiles();
	int addLocalDir(const std::string& path);
	void sendGetFileInfo(
		const PRNetAddr &receiver, const std::string& fileName, 
		const DataHash& hash, PRInt64 length);
	void parseFindFileByName(Packet *pkt);
};

#endif // __DFTS_FILEMANAGER_H_

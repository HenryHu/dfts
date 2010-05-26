// Last modified: 2010-05-27 01:37:14 henryhu

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
	void parseFindFileByName(Packet *pkt);
	void parseFindFileByNameReply(Packet *pkt);
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
	void sendSearch(
		const PRNetAddr &receiver, PRInt32 id, const std::string& pattern);
	void sendGetFileInfo(
		const PRNetAddr &receiver, const std::string& fileName, 
		const DataHash& hash, PRInt64 length);
};

#endif // __DFTS_FILEMANAGER_H_

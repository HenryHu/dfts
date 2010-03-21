// Last modified: 2010-03-21 00:45:44 henryhu

#ifndef __DFTS_FILEMANAGER_H_
#define __DFTS_FILEMANAGER_H_

#include <prio.h>
#include "core.h"
#include "packet.h"

class Core;

class FileManager {
private:
	Core *core;

public:
	void parseFindFileByName(Packet *pkt);
	void parseFindBlockByID(Packet *pkt);
	FileManager(Core *c);
};

#endif // __DFTS_FILEMANAGER_H_

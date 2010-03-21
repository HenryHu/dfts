// Last modified: 2010-03-21 01:37:32 henryhu
#ifndef __DFTS_USERMANAGER_H_
#define __DFTS_USERMANAGER_H_

#include <prio.h>
#include "core.h"
#include "packet.h"

class Core;

class UserManager {
private:
	Core *core;

public:
	void parseFindNeighbour(Packet *pkt);
	void parseNeighbourReply(Packet *pkt);
	UserManager(Core *c);
	void findNeighbour();
};

#endif // __DFTS_USERMANAGER_H_


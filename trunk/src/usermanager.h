// Last modified: 2010-03-21 20:23:12 henryhu
#ifndef __DFTS_USERMANAGER_H_
#define __DFTS_USERMANAGER_H_

#include <prio.h>
#include "core.h"
#include "packet.h"
#include "userhash.h"
#include <string>

class Core;

class UserManager {
private:
	Core *core;
	UserHash hash;

public:
	void parseFindNeighbour(Packet *pkt);
	void parseNeighbourReply(Packet *pkt);
	UserManager(Core *c);
	void findNeighbour();
	void addUser(const std::string& name, const std::string& key, PRUint32 ip, PRUint16 port);
};

#endif // __DFTS_USERMANAGER_H_


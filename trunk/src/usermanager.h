// Last modified: 2010-05-27 23:43:39 henryhu
#ifndef __DFTS_USERMANAGER_H_
#define __DFTS_USERMANAGER_H_

#include <prio.h>
#include "core.h"
#include "packet.h"
#include "userhash.h"
#include <string>
#include <list>
#include <prlock.h>

class Core;

class UserManager {
private:
	Core *core;
	UserHash hash;
	std::list<User *> neighbourList, otherList;
	PRLock *nlLock, *olLock, *hashLock;

public:
	void parseFindNeighbour(Packet *pkt);
	void parseNeighbourReply(Packet *pkt);
	UserManager(Core *c);
	void findNeighbour();
	User* findUser(PRUint32 ip, PRUint16 port, bool& isNeighbour);
	void addUser(const std::string& name, const std::string& key, PRUint32 ip, PRUint16 port,
			bool isNeighbour);
	std::list<User *> getNeighbourList();
	std::list<User *> getOtherList();
};

#endif // __DFTS_USERMANAGER_H_


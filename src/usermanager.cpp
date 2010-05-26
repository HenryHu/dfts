// Last modified: 2010-05-20 11:06:24 henryhu
#include "usermanager.h"
#include "config.h"
#include "netmgr.h"
#include "keymgr.h"
#include "cfgmgr.h"
#include "intercmd.h"
#include <prnetdb.h>
#include <string>
#include <iostream>
#include "userhash.h"
#include <prlock.h>
using namespace std;

void UserManager::parseFindNeighbour(Packet *pkt)
{
	LogMsg(LOG_DEBUG,"parsing find neighbour\n");

	PRUint16 hisPort = pkt->getRPort();
	string userName = pkt->fetchStr();
	string pubKey = pkt->fetchStr();
	// Add user to database
	addUser(userName, pubKey, pkt->getAddr().inet.ip, hisPort, true);

	// Send reply
	LogMsg(LOG_DEBUG, "his port: %d\n", hisPort);
	PRInt16 rtype = INT_CMD_NEIGHBOUR_REPLY;
	Packet *rpkt = new Packet(pkt->getRAddr(), rtype, 500, INTERCONNECT_PORT);
	rpkt->appendWord(INTERCONNECT_PORT);
	rpkt->appendStr(core->getCfgMgr()->getName());
	rpkt->appendStr(core->getKeyMgr()->getPubKey());
	core->getNetMgr()->sendMsg(rpkt, rtype);
}

void UserManager::parseNeighbourReply(Packet *pkt)
{
	LogMsg(LOG_DEBUG,"parsing neighbour reply\n");
}

UserManager::UserManager(Core *c)
: core(c)
{
	nlLock = PR_NewLock();
	olLock = PR_NewLock();
	hashLock = PR_NewLock();
}

void UserManager::findNeighbour()
{
	PRNetAddr addr;
	addr.inet.port = PR_htons(INTERCONNECT_PORT);
	addr.inet.family = PR_AF_INET;
	addr.inet.ip = PR_htonl(PR_INADDR_BROADCAST);
	PRInt16 type = INT_CMD_FIND_NEIGHBOUR;
	Packet *pkt = new Packet(addr, type, 500, INTERCONNECT_PORT);
	pkt->appendWord(INTERCONNECT_PORT);
	pkt->appendStr(core->getCfgMgr()->getName());
	pkt->appendStr(core->getKeyMgr()->getPubKey());
	core->getNetMgr()->sendMsg(pkt, type);
}

void UserManager::addUser(const string& name, const string& key, PRUint32 ip, PRUint16 port,
		bool isNeighbour)
{
	PR_Lock(hashLock);
	User *user = hash.findByKey(key);
	if (user == NULL)
	{
		user = new User(name, key, ip, port);
		hash.insert(user);
		if (isNeighbour)
		{
			PR_Lock(nlLock);
			neighbourList.push_front(user);
			user->setIter(neighbourList.begin());
			PR_Unlock(nlLock);
		} else {
			PR_Lock(olLock);
			otherList.push_front(user);
			user->setIter(otherList.begin());
			PR_Unlock(olLock);
		}
	} else {
		user->setName(name);
		user->setIP(ip);
		user->setPort(port);
	}
	PR_Unlock(hashLock);
}

list<User *> UserManager::getNeighbourList()
{
	PR_Lock(nlLock);
	list<User *> ret;
	for (list<User*>::iterator it = neighbourList.begin(); it!=neighbourList.end(); it++)
	{
		User *user = new User(**it);
		ret.push_back(user);
	}
	PR_Unlock(nlLock);
	return ret;
}

list<User *> UserManager::getOtherList()
{
	PR_Lock(olLock);
	list<User *> ret;
	for (list<User*>::iterator it = otherList.begin(); it!=otherList.end(); it++)
	{
		User *user = new User(**it);
		ret.push_back(user);
	}
	PR_Unlock(olLock);
	return ret;
}

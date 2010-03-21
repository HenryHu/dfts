// Last modified: 2010-03-21 01:47:10 henryhu
#include "usermanager.h"
#include "config.h"
#include "netmgr.h"
#include "intercmd.h"
#include <prnetdb.h>

void UserManager::parseFindNeighbour(Packet *pkt)
{
	LogMsg(LOG_DEBUG,"parsing find neighbour\n");
	PRNetAddr addr = pkt->getAddr();
	addr.inet.port = PR_htons(INTERCONNECT_PORT);
	core->getNetMgr()->sendMsg(new Packet(addr, INT_CMD_NEIGHBOUR_REPLY, 100), 
			INT_CMD_NEIGHBOUR_REPLY);
}

void UserManager::parseNeighbourReply(Packet *pkt)
{
	LogMsg(LOG_DEBUG,"parsing neighbour reply\n");
}

UserManager::UserManager(Core *c)
: core(c) {}

void UserManager::findNeighbour()
{
	PRNetAddr addr;
	addr.inet.port = PR_htons(INTERCONNECT_PORT);
	addr.inet.family = PR_AF_INET;
	addr.inet.ip = PR_htonl(PR_INADDR_BROADCAST);
	core->getNetMgr()->sendMsg(new Packet(addr, INT_CMD_FIND_NEIGHBOUR, 100),
			INT_CMD_FIND_NEIGHBOUR);
}


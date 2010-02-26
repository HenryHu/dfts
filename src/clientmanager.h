// Last modified: 2010-02-26 11:58:47 henryhu
#ifndef __DFTS_CLIENTMANAGER_H_
#define __DFTS_CLIENTMANAGER_H_
#include <prio.h>
#include <prthread.h>
#include <vector>
#include "clientservice.h"
#include "core.h"

class ClientManager {
private:
	PRNetAddr addr;
	PRFileDesc *servsock;
	PRThread *servthr;
	std::vector<ClientService *> clients;
	Core *core;

public:
	void run();
	ClientManager(const PRNetAddr &addr, Core *c);
	PRStatus start();
	PRThread *getThread();
};

#endif // __DFTS_CLIENTMANAGER_H_

// Last modified: 2010-02-26 16:50:01 henryhu
//
#ifndef __DFTS_CLIENTSERVICE_H_
#define __DFTS_CLIENTSERVICE_H_
#include <prio.h>
#include <prthread.h>
#include "core.h"
#include "clientcommand.h"
class ClientService {
private:
	Core *core;
	PRNetAddr servAddr;
	PRNetAddr cliAddr;
	PRFileDesc *cliSock;
	PRThread *thread;
	ClientCommand parseCmd(char *cmd);
	void findEOL();

public:
	ClientService(PRFileDesc *csock, const PRNetAddr &servaddr, const PRNetAddr &cliaddr,
			Core *c);
	PRStatus start();
	void run();
};

#endif // __DFTS_CLIENTSERVICE_H_

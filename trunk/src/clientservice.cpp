#include "clientservice.h"
#include "core.h"
#include <prio.h>
#include <prthread.h>
#include "config.h"
#include <stdio.h>
#include "threadwrap.h"
#include "clientcommand.h"
#include <strings.h>
#include "usermanager.h"
#include <list>
#include "user.h"
#include <prnetdb.h>
#include <prprf.h>
using namespace std;

ClientService::ClientService(PRFileDesc *csock, 
		const PRNetAddr &servaddr, const PRNetAddr &cliaddr,
		Core *c)
{
	cliSock = csock;
	servAddr = servaddr;
	cliAddr= cliaddr;
	core = c;
	thread = NULL;
}

void ClientService::run()
{
	char cmd[5];
	int errcnt = 0;
	bool closeConn = false;
	while (true)
	{
		int ret = PR_Recv(cliSock, cmd, 4, 0, PR_INTERVAL_NO_TIMEOUT);
		if (ret == -1)
		{
			LogMsg(LOG_WARN, "failed to receive client command.\n");
			ShowPRError();
			errcnt++;
			if (errcnt > CLIENT_SERVICE_ERR_LIMIT)
				break;
			continue;
		}
		if (ret == 0)
		{
			LogMsg(LOG_DEBUG, "client disconnected.\n");
			break;
		}
		if (ret != 4)
		{
			LogMsg(LOG_WARN, "invalid command len %d\n", ret);
			continue;
		}
		ClientCommand cc = parseCmd(cmd);
		switch (cc)
		{
			case CLI_CMD_QUIT:
				LogMsg(LOG_DEBUG, "client quit.\n");
				closeConn = true;
				break;
			case CLI_CMD_FIND_NEIGHBOUR:
				LogMsg(LOG_DEBUG, "find neighbour.\n");
				findEOL();
				// XXX call userManager to find neighbour
				core->getUserManager()->findNeighbour();
				break;
			case CLI_CMD_GET_NEIGHBOUR:
				{
				LogMsg(LOG_DEBUG, "get neighbour.\n");
				findEOL();
				// from userManager get neighbour
				list<User *> ret = core->getUserManager()->getNeighbourList();
				char *buf = new char[500];
				char *buf2 = new char[100];
				PRNetAddr addr;
				addr.inet.family = PR_AF_INET;
				for (list<User *>::iterator it = ret.begin(); it!=ret.end(); it++)
				{
					User *user = *it;
					addr.inet.ip = user->getIP();
					PR_NetAddrToString(&addr, buf2, 100);
					int len = PR_snprintf(buf, 500, "%s %s %d %s", user->getKey().c_str(), buf2,
							user->getPort(), user->getName().c_str());
					// PR_snprintf ensures that NULL terminates
					// and len does not include NULL
					buf[len] = '\n';
					PR_Send(cliSock, buf, len+1, 0, PR_INTERVAL_NO_TIMEOUT);
				}
				PR_Send(cliSock, "EOL\n", 4, 0, PR_INTERVAL_NO_TIMEOUT);
				break;
				}
			case CLI_CMD_GET_OTHER:
				{
				LogMsg(LOG_DEBUG, "get other people.\n");
				findEOL();
				// from userManager get neighbour
				list<User *> ret = core->getUserManager()->getOtherList();
				char *buf = new char[500];
				char *buf2 = new char[100];
				PRNetAddr addr;
				addr.inet.family = PR_AF_INET;
				for (list<User *>::iterator it = ret.begin(); it!=ret.end(); it++)
				{
					User *user = *it;
					addr.inet.ip = user->getIP();
					PR_NetAddrToString(&addr, buf2, 100);
					int len = PR_snprintf(buf, 500, "%s %s %d %s", user->getKey().c_str(), buf2,
							user->getPort(), user->getName().c_str());
					// PR_snprintf ensures that NULL terminates
					// and len does not include NULL
					buf[len] = '\n';
					PR_Send(cliSock, buf, len+1, 0, PR_INTERVAL_NO_TIMEOUT);
				}
				PR_Send(cliSock, "EOL\n", 4, 0, PR_INTERVAL_NO_TIMEOUT);
				break;
				}
			default:
				LogMsg(LOG_WARN, "unknown command %c%c%c%c\n", 
						cmd[0], cmd[1], cmd[2], cmd[3]);
				findEOL();
		}
		if (closeConn) break;
	}
	PR_Close(cliSock);
}

PRStatus ClientService::start()
{
	LogMsg(LOG_DEBUG, "client connected!\n");
	thread = PR_CreateThread(PR_USER_THREAD, &thread_wrapper<ClientService>, this,
			PR_PRIORITY_LOW, PR_LOCAL_THREAD, PR_JOINABLE_THREAD,
			0);
	if (!thread)
		return PR_FAILURE;
}

ClientCommand ClientService::parseCmd(char *cmd)
{
	for (int i=0; i<CLI_CMD_COUNT; i++)
	{
		if (strncasecmp(cmd, ClientCommandName[i], CLIENT_COMMAND_LEN) == 0)
			return (ClientCommand)i;
	}
	return CLI_CMD_UNKNOWN;
}

void ClientService::findEOL()
{
	char a;
	PR_Recv(cliSock, &a, 1, 0, PR_INTERVAL_NO_TIMEOUT);
	while (a != '\n') PR_Recv(cliSock, &a, 1, 0, PR_INTERVAL_NO_TIMEOUT);
}
	

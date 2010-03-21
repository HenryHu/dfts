// Last modified: 2010-03-21 22:43:20 henryhu
#include "clientmanager.h"
#include "config.h"
#include <prio.h>
#include <vector>
#include <arpa/inet.h>
#include "threadwrap.h"
#include <prnetdb.h>
using namespace std;

void ClientManager::run()
{
	servsock = PR_NewTCPSocket();
	if (!servsock)
	{
		LogMsg(LOG_ERROR, "failed to create server socket.\n");
		ShowPRError();
		return ;
	}

	PRSocketOptionData data;
	data.option = PR_SockOpt_Reuseaddr;
	data.value.reuse_addr = PR_TRUE;
	PR_SetSocketOption(servsock, &data);

	PRStatus ret = PR_Bind(servsock, &addr);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to bind server socket.\n");
		ShowPRError();
		PR_Close(servsock);
		return ;
	}

	ret = PR_Listen(servsock, CLIENT_MANAGER_BACKLOG_LEN);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to listen server socket.\n");
		ShowPRError();
		PR_Close(servsock);
		return ;
	}

	while (true)
	{
		PRNetAddr cliaddr;
		PRFileDesc *newcli = PR_Accept(servsock, &cliaddr, PR_INTERVAL_NO_TIMEOUT);
		if (!newcli)
		{
			LogMsg(LOG_WARN, "failed to accept client connection.\n");
			ShowPRError();
			return ;
		}

		ClientService *cs = new ClientService(newcli, addr, cliaddr, core);
		clients.push_back(cs);
		cs->start();
	}

}

PRStatus ClientManager::start()
{
	servthr = PR_CreateThread(PR_SYSTEM_THREAD, &thread_wrapper<ClientManager>, this, 
			PR_PRIORITY_NORMAL, PR_LOCAL_THREAD, PR_JOINABLE_THREAD,
			0);
	if (!servthr)
		return PR_FAILURE;
}

ClientManager::ClientManager(const PRNetAddr &a, Core *c) 
	: addr(a), servsock(NULL), servthr(NULL), core(c) {}

PRThread *ClientManager::getThread()
{
	return servthr;
}

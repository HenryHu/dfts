#include "clientmanager.h"
#include "msgreceiver.h"
#include "config.h"
#include <prio.h>
#include <prnetdb.h>

int main()
{
	PRNetAddr addr;
	addr.inet.family = PR_AF_INET;
	addr.inet.port = PR_htons(CLIENT_MANAGER_PORT);
	addr.inet.ip = PR_htonl(PR_INADDR_LOOPBACK);

	ClientManager cm(addr, NULL);
	cm.start();
	MsgReceiver mr(addr, INTERCONNECT_PORT, INTERCONNECT_PORT, NULL);
	mr.start();
	PR_JoinThread(cm.getThread());
	PR_JoinThread(mr.getThread());
	return 0;
}

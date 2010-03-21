#include "clientmanager.h"
#include "usermanager.h"
#include "netmgr.h"
#include "config.h"
#include <prio.h>
#include <prnetdb.h>

int main()
{
	PRNetAddr addr;
	addr.inet.family = PR_AF_INET;
	addr.inet.port = PR_htons(CLIENT_MANAGER_PORT);
	addr.inet.ip = PR_htonl(PR_INADDR_ANY);

	Core *core = new Core();
	UserManager *um = new UserManager(core);
	ClientManager cm(addr, core);
	cm.start();
	NetMgr mr(addr, INTERCONNECT_PORT, INTERCONNECT_PORT, core);
	core->setNetMgr(&mr);
	core->setUserMgr(um);
	mr.start();
	PR_JoinThread(cm.getThread());
	PR_JoinThread(mr.getThread());
	return 0;
}

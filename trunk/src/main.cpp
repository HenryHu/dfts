#include "clientmanager.h"
#include "usermanager.h"
#include "netmgr.h"
#include "cfgmgr.h"
#include "config.h"
#include <prio.h>
#include <prnetdb.h>
#include "keymgr.h"
#include "datahasher.h"
#include <iostream>
#include "filemanager.h"
using namespace std;

int main()
{
	PRNetAddr addr;
	addr.inet.family = PR_AF_INET;
	addr.inet.port = PR_htons(CLIENT_MANAGER_PORT);
	addr.inet.ip = PR_htonl(PR_INADDR_ANY);

	Core *core = new Core();
	UserManager *um = new UserManager(core);
	KeyMgr *km = new KeyMgr("pub.key", "priv.key");
	CfgMgr *cfgm = new CfgMgr();
	km->start();
	ClientManager cm(addr, core);
	cm.start();
	NetMgr mr(addr, INTERCONNECT_PORT, INTERCONNECT_PORT, core);
	FileManager fm(core);
	fm.addLocalDir("/tmp/plugtmp-1");
	core->setNetMgr(&mr);
	core->setUserMgr(um);
	core->setKeyMgr(km);
	core->setCfgMgr(cfgm);
	core->setFileMgr(&fm);
	mr.start();

	PR_StringToNetAddr("192.168.1.109", &addr);
	addr.inet.port = PR_htons(INTERCONNECT_PORT);
	fm.sendSearch(addr, 12345, ".*");
	fm.sendGetFileInfo(addr, "plugin-crossdomain.xml", DataHash("92498502AB185CF12C0C8BC8CA7AE14964FC97BE"), 145);

	PR_JoinThread(cm.getThread());
	PR_JoinThread(mr.getThread());
	return 0;
}

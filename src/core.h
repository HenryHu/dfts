// Last modified: 2010-03-21 15:33:45 henryhu
//
#ifndef __DFTS_CORE_H_
#define __DFTS_CORE_H_

class UserManager;
class FileManager;
class NetMgr;
class CfgMgr;
class KeyMgr;

class Core {
private:
	UserManager *userManager;
	FileManager *fileManager;
	NetMgr *netMgr;
	KeyMgr *keyMgr;
	CfgMgr *cfgMgr;
public:
	UserManager *getUserManager();
	FileManager *getFileManager();
	NetMgr *getNetMgr();
	CfgMgr *getCfgMgr();
	KeyMgr *getKeyMgr();
	void setNetMgr(NetMgr *nm) { netMgr = nm; }
	void setUserMgr(UserManager *um) { userManager = um; }
	void setKeyMgr(KeyMgr *km) { keyMgr = km; }
	void setCfgMgr(CfgMgr *cm) { cfgMgr = cm; }
};

#endif // __DFTS_SERVER_H_

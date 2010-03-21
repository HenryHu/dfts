// Last modified: 2010-03-21 01:30:38 henryhu
//
#ifndef __DFTS_CORE_H_
#define __DFTS_CORE_H_

class UserManager;
class FileManager;
class NetMgr;

class Core {
private:
	UserManager *userManager;
	FileManager *fileManager;
	NetMgr *netMgr;
public:
	UserManager *getUserManager();
	FileManager *getFileManager();
	NetMgr *getNetMgr();
	void setNetMgr(NetMgr *nm) { netMgr = nm; }
	void setUserMgr(UserManager *um) { userManager = um; }
};

#endif // __DFTS_SERVER_H_

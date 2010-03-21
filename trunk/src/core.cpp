#include "core.h"

UserManager *Core::getUserManager()
{
	return userManager;
}

FileManager *Core::getFileManager()
{
	return fileManager;
}

NetMgr *Core::getNetMgr()
{
	return netMgr;
}

CfgMgr *Core::getCfgMgr()
{
	return cfgMgr;
}

KeyMgr *Core::getKeyMgr()
{
	return keyMgr;
}


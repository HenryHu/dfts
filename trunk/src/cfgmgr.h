// Last modified: 2010-03-21 15:50:22 henryhu
#ifndef __DFTS_CFGMGR_H_
#define __DFTS_CFGMGR_H_
#include <string>

class CfgMgr {
private:
	std::string name;

public:
	std::string getName();
	CfgMgr();
};

#endif // __DFTS_CFGMGR_H_

// Last Modified: 2010-03-21 20:25:27 henryhu
#ifndef __DFTS_USER_H_
#define __DFTS_USER_H_
#include <string>
#include <prtypes.h>

class User {
private:
	std::string name;
	std::string key;
	PRUint32 ip;
	PRUint16 port;

public:
	User(const std::string& n, const std::string& k, PRUint32 i, PRUint16 p);
	const std::string& getName();
	const std::string& getKey();
	PRUint16 getPort();
	void setPort(PRUint16 p);
	void setIP(PRUint32 i);
	void setName(const std::string& n);
};

#endif // __DFTS_USER_H_

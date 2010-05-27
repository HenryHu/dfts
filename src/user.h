// Last Modified: 2010-05-27 23:56:18 henryhu
#ifndef __DFTS_USER_H_
#define __DFTS_USER_H_
#include <string>
#include <prtypes.h>
#include <list>
#include <prio.h>

class User {
private:
	std::string name;
	std::string key;
	PRUint32 ip;
	PRUint16 port;
	std::list<User *>::iterator it;

public:
	User(const std::string& n, const std::string& k, PRUint32 i, PRUint16 p);
	const std::string& getName();
	const std::string& getKey();
	PRUint16 getPort();
	PRUint32 getIP();
	void setPort(PRUint16 p);
	void setIP(PRUint32 i);
	void setName(const std::string& n);
	void setIter(std::list<User *>::iterator i);
	PRNetAddr getAddr();
};

#endif // __DFTS_USER_H_

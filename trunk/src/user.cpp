// Last Modified: 2010-05-27 23:56:55 henryhu

#include "user.h"
#include <prtypes.h>
#include <string>
#include <prnetdb.h>
using namespace std;

User::User(const string& n, const string& k, PRUint32 i, PRUint16 p)
	:name(n), key(k), ip(i), port(p) {}

const string& User::getName()
{
	return name;
}

const string& User::getKey()
{
	return key;
}

PRUint16 User::getPort()
{
	return port;
}

void User::setPort(PRUint16 p)
{
	port = p;
}

void User::setIP(PRUint32 i)
{
	ip = i;
}

void User::setName(const string& n)
{
	name = n;
}

void User::setIter(std::list<User *>::iterator i)
{
	it = i;
}

PRUint32 User::getIP()
{
	return ip;
}

PRNetAddr User::getAddr()
{
	PRNetAddr ret;
	ret.inet.ip = PR_htonl(ip);
	ret.inet.port = PR_htons(port);
	ret.inet.family = AF_INET;
	return ret;
}


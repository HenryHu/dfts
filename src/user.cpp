// Last Modified: 2010-03-21 20:26:07 henryhu

#include "user.h"
#include <prtypes.h>
#include <string>
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

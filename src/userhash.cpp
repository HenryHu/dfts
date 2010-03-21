// Last Modified: 2010-03-21 20:40:27 henryhu
#include "userhash.h"
#include "config.h"
#include <string>
using namespace std;

UserHash::UserHash()
	: PRIME_A(31)
{
	size = USERHASH_INIT_SIZE;
	list = new UserHashNode*[USERHASH_INIT_SIZE];
	for (int i=0; i<USERHASH_INIT_SIZE; i++)
		list[i] = NULL;
}

User *UserHash::findByKey(const string& key)
{
	int hash = strHash(key);
	UserHashNode *u = list[hash];
	while (u != NULL)
	{
		if (u->getKey() == key)
		{
			return u->getUser();
		}
		u = u->getNext();
	}
	return NULL;
}

void UserHash::insert(User *user)
{
	int hash = strHash(user->getKey());
	UserHashNode *u = new UserHashNode(user, list[hash]);
	list[hash] = u;
}

const string& UserHash::UserHashNode::getKey()
{
	return user->getKey();
}

User *UserHash::UserHashNode::getUser()
{
	return user;
}

UserHash::UserHashNode *UserHash::UserHashNode::getNext()
{
	return next;
}

UserHash::UserHashNode::UserHashNode(User *u, UserHashNode *n)
{
	user = u;
	next = n;
}

long UserHash::strHash(const string& x)
{
	long a = x[0] * PRIME_A + x[x.length() / 4];
	a = (a % (size-1)) * PRIME_A + x[x.length() / 2];
	return (a % (size-1));
}


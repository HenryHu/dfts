// Last Modified: 2010-03-21 20:38:54 henryhu
#ifndef __DFTS_USERHASH_H_
#define __DFTS_USERHASH_H_
#include "user.h"
#include <string>

class UserHash {
private:
	const int PRIME_A;
	class UserHashNode {
	private:
		User *user;
		UserHashNode *next;
	public:
		UserHashNode(User *u,UserHashNode *n);
		const std::string& getKey();
		User *getUser();
		UserHashNode *getNext();
	};
	UserHashNode **list;
	int size;

public:
	User *findByKey(const std::string& key);
	UserHash();
	long strHash(const std::string& x);
	void insert(User *user);
};

#endif // __DFTS_USERHASH_H_


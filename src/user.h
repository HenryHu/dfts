// Last Modified: 2010-03-19 11:16:59 henryhu
#ifndef __DFTS_USER_H_
#define __DFTS_USER_H_

class User {
private:
	string name;
	PublicKey key;
	PRNetAddr addr;

public:
	User(const string& n, const PRNetAddr& a, const PublicKey& k);
};

#endif // __DFTS_USER_H_

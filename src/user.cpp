// Last Modified: 2010-03-19 11:18:00 henryhu

#include "user.h"

User::User(const string& n, const PRNetAddr& a, const PublicKey& k)
	:name(n), addr(a), key(k) {}

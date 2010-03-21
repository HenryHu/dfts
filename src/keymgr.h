// Last modified: 2010-03-21 14:53:41 henryhu
#ifndef __DFTS_KEYMGR_H_
#define __DFTS_KEYMGR_H_

#include <files.h>
#include <string>

class KeyMgr {
private:
	char *filePubKey, *filePrivKey;
	CryptoPP::FileSource *pubFile, *privFile;
public:
	void start();
	void generateKeys();
	KeyMgr(char *pubKey, char *privKey);
	std::string getPubKey();
};

#endif // __DFTS_KEYMGR_H_


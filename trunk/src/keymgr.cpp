#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#define CRYPTOPP_DEFAULT_NO_DLL

#include "keymgr.h"
#include <rsa.h>
#include <prio.h>
#include <base64.h>
#include <osrng.h>
#include "config.h"
#include <cryptlib.h>
#include <filters.h>
#include <string>

using namespace CryptoPP;
using namespace std;

void KeyMgr::start()
{
	PRFileInfo info;
	PRStatus ret = PR_GetFileInfo(filePubKey, &info);
	if ((ret == PR_SUCCESS) && (info.size != 0))
	{
		ret = PR_GetFileInfo(filePrivKey, &info);
		if ((ret == PR_SUCCESS) && (info.size != 0))
		{
			pubFile = new FileSource(filePubKey, true, new Base64Decoder);
			privFile = new FileSource(filePrivKey, true, new Base64Decoder);
		} else generateKeys();
	} else generateKeys();
}

KeyMgr::KeyMgr(char *pubKey, char *privKey)
{
	filePubKey = new char[strlen(pubKey)+1];
	filePrivKey = new char[strlen(privKey)+1];
	strcpy(filePubKey, pubKey);
	strcpy(filePrivKey, privKey);
}

void KeyMgr::generateKeys()
{
	AutoSeededRandomPool rng;
	InvertibleRSAFunction privkey;
	privkey.Initialize(rng, RSA_KEY_LENGTH);

	Base64Encoder privkeysink(new FileSink(filePrivKey));
	privkey.DEREncode(privkeysink);
	privkeysink.MessageEnd();

	RSAFunction pubkey(privkey);
	Base64Encoder pubkeysink(new FileSink(filePubKey));
	pubkey.DEREncode(pubkeysink);
	pubkeysink.MessageEnd();

	pubFile = new FileSource(filePubKey, true, new Base64Decoder);
	privFile = new FileSource(filePrivKey, true, new Base64Decoder);
}

string KeyMgr::getPubKey()
{
	string sPubKey;
	FileSource(filePubKey, true, new StringSink(sPubKey));
	return sPubKey;
}


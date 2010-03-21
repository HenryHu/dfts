// Last modified: 2010-03-21 15:33:14 henryhu

#ifndef __DFTS_PACKET_H_
#define __DFTS_PACKET_H_

#include <prio.h>
#include <string>

class Packet {
private:
	char *data;
	int len, buflen;
	PRNetAddr addr;
	char *ptr;

public:
	Packet(const PRNetAddr& a, char *d, int l);
	Packet(const PRNetAddr& a, PRInt16 type, int dlen);
	char *getData();
	int getLen();
	PRNetAddr *getPAddr();
	const PRNetAddr& getAddr();
	void appendStr(const std::string& s);
	void appendWord(PRInt16 i);
	PRInt16 fetchWord();
	PRInt32 fetchInt();
	std::string fetchStr();
	void moreSpace(int space);
};

#endif // __DFTS_PACKET_H_


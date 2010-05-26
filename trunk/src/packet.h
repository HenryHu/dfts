// Last modified: 2010-05-27 00:51:06 henryhu

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
	PRInt16 rPort;
	PRInt16 cmd;

public:
	Packet(const PRNetAddr& a, char *d, int l);
	Packet(const PRNetAddr& a, PRInt16 type, int dlen);
	Packet(const PRNetAddr& a, PRInt16 type, int dlen, PRInt16 rPt);
	char *getData();
	int getLen();
	PRNetAddr *getPAddr();
	const PRNetAddr& getAddr();
	const PRNetAddr getRAddr();
	void appendStr(const std::string& s);
	void appendWord(PRInt16 i);
	void appendByte(PRInt8 i);
	void appendQWord(PRInt64 i);
	void appendInt(PRInt32 i);
	PRInt16 fetchWord();
	PRInt32 fetchInt();
	PRInt8 fetchByte();
	std::string fetchStr();
	PRInt64 fetchQWord();
	void moreSpace(int space);
	PRInt16 getRPort();
	void setRPort(PRInt16 r);
	PRInt16 getCmd();
	void setCmd(PRInt16 c);
};

#endif // __DFTS_PACKET_H_


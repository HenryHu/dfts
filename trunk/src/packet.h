// Last modified: 2010-03-21 01:13:18 henryhu

#ifndef __DFTS_PACKET_H_
#define __DFTS_PACKET_H_

#include <prio.h>

class Packet {
private:
	char *data;
	int len;
	PRNetAddr addr;
	char *ptr;

public:
	Packet(const PRNetAddr& a, char *d, int l);
	Packet(const PRNetAddr& a, PRInt16 type, int dlen);
	char *getData();
	int getLen();
	PRNetAddr *getPAddr();
	const PRNetAddr& getAddr();
};

#endif // __DFTS_PACKET_H_


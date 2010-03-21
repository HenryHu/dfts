// Last modified: 2010-03-21 01:32:30 henryhu
#include "packet.h"
#include <prnetdb.h>

Packet::Packet(const PRNetAddr& a, char *d, int l)
	: data(d), len(l), addr(a), ptr(NULL) {}

Packet::Packet(const PRNetAddr& a, PRInt16 type, int dlen)
{
	addr = a;
	data = new char[dlen];
	ptr = data + 2;
	len = dlen;
	*(PRInt16 *)data = PR_htons(type);
}

char *Packet::getData()
{
	return data;
}

int Packet::getLen()
{
	return len;
}

PRNetAddr *Packet::getPAddr()
{
	return &addr;
}

const PRNetAddr &Packet::getAddr()
{
	return addr;
}

// Last modified: 2010-05-27 02:25:27 henryhu
#include "packet.h"
#include <prnetdb.h>
#include <string>
using namespace std;

Packet::Packet(const PRNetAddr& a, char *d, int l)
	: data(d), len(l), addr(a), ptr(d) {}

// Pakcet with type
Packet::Packet(const PRNetAddr& a, PRInt16 type, int dlen)
{
	addr = a;
	data = new char[dlen];
	ptr = data + 2;
	buflen = dlen;
	len = 4;
	*(PRInt16 *)data = PR_htons(type);
	*(PRInt16 *)ptr = PR_htons(0);
	ptr += 2;
	rPort = 0;
}

// Packet with type and return port
Packet::Packet(const PRNetAddr& a, PRInt16 type, int dlen, PRInt16 rPt)
{
	addr = a;
	rPort = rPt;
	data = new char[dlen];
	ptr = data + 2;
	buflen = dlen;
	len = 4;
	*(PRInt16 *)data = PR_htons(type);
	*(PRInt16 *)ptr = PR_htons(rPt);
	ptr += 2;
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

const PRNetAddr Packet::getRAddr()
{
	PRNetAddr raddr = addr;
	raddr.inet.port = PR_htons(rPort);
	return raddr;
}

void Packet::moreSpace(int space)
{
	if (buflen < len + space)
	{
		while (buflen < len + space) buflen *= 2;
		char *newbuf = new char[buflen];
		for (int i=0; i<len; i++) newbuf[i] = data[i];
		delete[] data;
		data = newbuf;
		ptr = newbuf + len;
	}
}

void Packet::appendStr(const string& s)
{
	int slen = s.length();
	moreSpace(4 + slen);
	*(PRInt32*)ptr = PR_htonl(slen);
	ptr += 4;
	for (int i=0; i<slen; i++)
		*ptr++ = s[i];
	len = len + 4 + slen;
}

void Packet::appendWord(PRInt16 i)
{
	moreSpace(2);
	*(PRInt16*)ptr = PR_htons(i);
	ptr += 2;
	len += 2;
}

void Packet::appendInt(PRInt32 i)
{
	moreSpace(4);
	*(PRInt32 *)ptr = PR_htonl(i);
	ptr += 4;
	len += 4;
}

PRInt16 Packet::fetchWord()
{
	if (len < 2)
		return -1;

	PRInt16 ret = PR_ntohs(*(PRInt16 *)ptr);
	ptr+=2;
	len-=2;
	return ret;
}

string Packet::fetchStr()
{
	PRInt32 slen = fetchInt();
	if (slen < 0)
		return "";

	if (len < slen)
		return "";

	string ret(ptr, slen);
	ptr += slen;
	len -= slen;
	return ret;
}

PRInt32 Packet::fetchInt()
{
	if (len < 4)
		return -1;

	PRInt32 ret = PR_ntohl(*(PRInt32 *)ptr);
	ptr += 4;
	len -= 4;
	return ret;
}

PRInt8 Packet::fetchByte()
{
	if (len < 1)
		return -1;

	PRInt8 ret = *ptr;
	ptr+=1;
	len-=1;
	return ret;
}

void Packet::appendByte(PRInt8 i)
{
	moreSpace(1);
	*ptr = i;
	ptr += 1;
	len += 1;
}

PRInt16 Packet::getRPort()
{
	return rPort;
}

void Packet::setRPort(PRInt16 r)
{
	rPort = r;
}

PRInt16 Packet::getCmd()
{
	return cmd;
}

void Packet::setCmd(PRInt16 c)
{
	cmd = c;
}

PRInt64 Packet::fetchQWord()
{
	if (len < 8)
		return -1;

	PRUint64 ret = 0;
	for (int i=0; i<8; i++)
	{
		ret = (ret << 8) | (unsigned char)(*ptr);
//		printf("ret: %llx\n", ret);
		ptr++;
	}
	len-=8;
	return ret;
}

void Packet::appendQWord(PRInt64 i)
{
	moreSpace(8);
//	printf("i: %llx\n", i);
	PRUint64 ii = i;
	PRUint64 mask = (PRUint64)0xFF << 56;
	for (int i=0; i<8; i++)
	{
		*ptr = (ii & mask) >> (8*(7-i));
//		printf("%llx ", (ii & mask));
//		printf("%x,", (unsigned char)*ptr);
		ptr++;
		mask >>= 8;
	}
//	printf("\n");

	len += 8;
}


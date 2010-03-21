// Last modified: 2010-03-21 15:59:52 henryhu
#include "packet.h"
#include <prnetdb.h>
#include <string>
using namespace std;

Packet::Packet(const PRNetAddr& a, char *d, int l)
	: data(d), len(l), addr(a), ptr(d) {}

Packet::Packet(const PRNetAddr& a, PRInt16 type, int dlen)
{
	addr = a;
	data = new char[dlen];
	ptr = data + 2;
	buflen = dlen;
	len = 2;
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


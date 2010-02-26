// Last modified: 2010-02-26 23:16:24 henryhu
#ifndef __DTFS_MSGRECEIVER_H_
#define __DTFS_MSGRECEIVER_H_
#include <prio.h>
#include <prthread.h>
#include "core.h"

class MsgReceiver {
private:
	PRFileDesc *udpSock;
	PRFileDesc *tcpSock;
	PRThread *thread;
	PRNetAddr addr;
	int udpPort;
	int tcpPort;
	Core *core;
	void processConnection(PRFileDesc *conn, PRNetAddr *addr, PRInt16 cmd);
	void parsePacket(const PRNetAddr& src, int len, char *buffer);

public:
	void run();
	PRStatus start();
	MsgReceiver(const PRNetAddr& a, int uport, int tport, Core *c);
	PRStatus sendMsg(const PRNetAddr& target, int len, char *data);
	PRThread *getThread();

};

#endif // __DTFS_MSGRECEIVER_H_

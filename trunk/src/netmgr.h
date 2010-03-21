// Last modified: 2010-03-21 01:02:42 henryhu
#ifndef __DTFS_MSGRECEIVER_H_
#define __DTFS_MSGRECEIVER_H_
#include <prio.h>
#include <prthread.h>
#include "core.h"
#include <prtpool.h>
#include "packet.h"

class NetMgr {
private:
	PRFileDesc *udpSock;
	PRFileDesc *tcpSock;
	PRThread *thread;
	PRThreadPool *pool;
	PRNetAddr addr;
	int udpPort;
	int tcpPort;
	Core *core;
	class TCPReceiver {
	private:
		PRFileDesc *conn;
		PRNetAddr addr;
		PRInt16 cmd;
		NetMgr *parent;
	public:
		void run();
		TCPReceiver(PRFileDesc *c, const PRNetAddr& a, PRInt16 cm,
				NetMgr *p);
	};
	class TCPSender {
	private:
		Packet *pkt;
		NetMgr *parent;
	public:
		void run();
		TCPSender(Packet *packet, NetMgr *p);
		~TCPSender();
	};

	void parsePacket(Packet *pkt);

public:
	void run();
	PRStatus start();
	NetMgr(const PRNetAddr& a, int uport, int tport, Core *c);
	PRStatus sendMsg(Packet *pkt, PRInt16 cmd);
	PRThread *getThread();

};

#endif // __DTFS_MSGRECEIVER_H_

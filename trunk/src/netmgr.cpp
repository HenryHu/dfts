// Last modified: 2010-03-21 02:04:41 henryhu
#include "netmgr.h"
#include "threadwrap.h"
#include "config.h"
#include <prio.h>
#include <prthread.h>
#include <prnetdb.h>
#include "intercmd.h"
#include <prerror.h>
#include "packet.h"
#include "usermanager.h"
#include "filemanager.h"

NetMgr::NetMgr(const PRNetAddr &a, int uport, int tport, Core *c)
{
	addr = a;
	udpPort = uport;
	tcpPort = tport;
	core = c;
	thread = NULL;
	udpSock = NULL;
	tcpSock = NULL;
}

PRStatus NetMgr::start()
{
	thread = PR_CreateThread(PR_SYSTEM_THREAD, &thread_wrapper<NetMgr>, this,
			PR_PRIORITY_HIGH, PR_LOCAL_THREAD, PR_JOINABLE_THREAD,
			0);
	if (!thread)
		return PR_FAILURE;
}

PRThread *NetMgr::getThread()
{
	return thread;
}

void NetMgr::run()
{
	udpSock = PR_NewUDPSocket();
	tcpSock = PR_NewTCPSocket();
	if (!udpSock || !tcpSock)
	{
		LogMsg(LOG_ERROR, "failed to create interconnect socket.\n");
		ShowPRError();
		return;
	}

	addr.inet.port = PR_htons(udpPort);
	PRStatus ret = PR_Bind(udpSock, &addr);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to bind UDP interconnect socket.\n");
		ShowPRError();
		return ;
	}

	PRSocketOptionData sod;
	sod.option = PR_SockOpt_Broadcast;
	sod.value.broadcast = PR_TRUE;
	ret = PR_SetSocketOption(udpSock, &sod);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to enable broadcasting.\n");
		ShowPRError();
		return;
	}
	
	addr.inet.port = PR_htons(tcpPort);
	ret = PR_Bind(tcpSock, &addr);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to bind TCP interconnect socket.\n");
		ShowPRError();
		return ;
	}
	
	ret = PR_Listen(tcpSock, MSG_RECEIVER_BACKLOG_LEN);
	if (ret != PR_SUCCESS)
	{
		LogMsg(LOG_ERROR, "failed to listen interconnect socket.\n");
		ShowPRError();
		PR_Close(tcpSock);
		return ;
	}

	pool = PR_CreateThreadPool(MSG_INIT_THREADS, MSG_MAX_THREADS, MSG_STACK_SIZE);
	if (pool == NULL)
	{
		LogMsg(LOG_ERROR, "failed to create thread pool for messages.\n");
		ShowPRError();
		PR_Close(tcpSock);
		return;
	}

	PRPollDesc pd[2];

	char *udpBuffer = new char[UDP_PACKET_LEN_LIMIT];
	while (true)
	{
		pd[0].fd = udpSock;
		pd[1].fd = tcpSock;
		pd[0].in_flags = PR_POLL_READ | PR_POLL_EXCEPT;
		pd[1].in_flags = PR_POLL_READ | PR_POLL_EXCEPT;
		int ret = PR_Poll(pd, 2, PR_INTERVAL_NO_TIMEOUT);
		if (ret == -1)
		{
			LogMsg(LOG_ERROR, "failed to poll interconnect sockets.\n");
			ShowPRError();
			break;
		}
		if (pd[0].out_flags)
			if (pd[0].out_flags & PR_POLL_READ)
			{
				PRNetAddr remoteAddr;
				int len = PR_RecvFrom(udpSock, udpBuffer, 
						UDP_PACKET_LEN_LIMIT, 0, &remoteAddr, 
						PR_INTERVAL_NO_TIMEOUT);
				if (len > 0)
					parsePacket(new Packet(remoteAddr, udpBuffer, len));
				else
					LogMsg(LOG_WARN, "receive UDP packet failed.\n");
			} else {
				LogMsg(LOG_WARN, "unexcpected polling result.\n");
				if (pd[0].out_flags & PR_POLL_NVAL)
					break;
			}
		if (pd[1].out_flags)
			if (pd[1].out_flags & PR_POLL_READ)
			{
				PRFileDesc *tcpConn;
				PRNetAddr *remoteAddr;
				PRInt16 cmd;
				char *buf = new char[2 * sizeof(PRNetAddr) + 2];
				int ret = PR_AcceptRead(tcpSock, &tcpConn, &remoteAddr, 
						buf, 2, TCP_ACCEPT_TIMEOUT);
				cmd = *((PRInt16 *)buf);
				if (ret == -1)
					if (PR_GetError() == PR_IO_TIMEOUT_ERROR)
					{
						LogMsg(LOG_WARN, "connection establishment timeout.\n");
					} else {
						LogMsg(LOG_ERROR, "failed to accept connection.\n");
						ShowPRError();
					}
				else {
					if (ret == 2)
					{
						TCPReceiver *rcvr = new TCPReceiver(tcpConn,
								*remoteAddr, PR_ntohs(cmd), this);
						PR_QueueJob(pool, &thread_wrapper<TCPReceiver>, rcvr,
								PR_TRUE);
/*						PR_CreateThread(PR_USER_THREAD, 
								&thread_wrapper<TCPReceiver>, rcvr,
								PR_PRIORITY_LOW, PR_LOCAL_THREAD, 
								PR_JOINABLE_THREAD, 0);*/
					}
					else
						PR_Close(tcpConn);
				}
				delete buf;
			}
	}
	delete[] udpBuffer;
	PR_Close(udpSock);
	PR_Close(tcpSock);
}

NetMgr::TCPReceiver::TCPReceiver(PRFileDesc *c, const PRNetAddr &a, 
		PRInt16 cm, NetMgr *p)
:conn(c), addr(a), cmd(cm), parent(p) {}


void NetMgr::TCPReceiver::run()
{
	if (cmd < INT_CMD_LOSSABLE_LIMIT)
	{
		PRInt32 len;
		int ret = PR_Recv(conn, &len, 4, 0, TCP_HEADER_TIMEOUT);
		if (ret == 4)
		{
			len = ntohl(len);
			if (len < TCP_PACKET_LEN_LIMIT)
			{
				char *data = new char[len];
				int rlen = PR_Recv(conn, data, len, 0, TCP_LOSSABLE_TIMEOUT);
				if (rlen == len)
				{
					Packet *pkt = new Packet(addr, data, len);
					parent->parsePacket(pkt);
				}
				delete[] data;
			} else {
				LogMsg(LOG_DEBUG, "packet too long, discarded.\n");
			}
		} else {
			LogMsg(LOG_DEBUG, "packet too short, discarded.\n");
		}
		PR_Close(conn);
	} else {
		switch (cmd)
		{
		}
	}
	delete this;
}

NetMgr::TCPSender::TCPSender(Packet *packet, NetMgr *p)
:pkt(packet), parent(p) {}

NetMgr::TCPSender::~TCPSender()
{
	delete pkt;
}

void NetMgr::TCPSender::run()
{
	PRInt32 ret = PR_SendTo(parent->tcpSock, pkt->getData(), pkt->getLen(), 0, pkt->getPAddr(),
			TCP_SEND_TIMEOUT);
	// shall we release data?
	delete this;
}

void NetMgr::parsePacket(Packet *pkt)
{
	LogMsg(LOG_DEBUG, "lossable packet received. len: %d\n", pkt->getLen());
	if (pkt->getLen() < 2)
		return;
	PRInt16 cmd = PR_ntohs(*((PRInt16 *)(pkt->getData())));
	switch (cmd)
	{
		// They should take care of the packet
		case INT_CMD_FIND_NEIGHBOUR:
			LogMsg(LOG_DEBUG, "someone is finding neighbour\n");
//			Tell usermanager about new neighbour
			core->getUserManager()->parseFindNeighbour(pkt);
//			NeighbourReplyPacket nrp(core->getName());
//			sendMsg(addr, nrp.getLen(), nrp.getData());
			break;
		case INT_CMD_NEIGHBOUR_REPLY:
			LogMsg(LOG_DEBUG, "received reply from neighbour\n");
			core->getUserManager()->parseNeighbourReply(pkt);
//			core->getUserManager()->parseNeighbourReply(addr, len, data);
			break;
		case INT_CMD_FIND_FILE_BY_NAME:
			LogMsg(LOG_DEBUG, "someone is finding file by name\n");
			core->getFileManager()->parseFindFileByName(pkt);
			break;
		case INT_CMD_FIND_FILE_BY_ID:
			core->getFileManager()->parseFindBlockByID(pkt);
			break;
		default:
			LogMsg(LOG_DEBUG, "unknown message: %d\n", cmd);
			delete pkt;
	}
}

PRStatus NetMgr::sendMsg(
		Packet *pkt, PRInt16 cmd)
{
	if ((cmd > INT_CMD_LOSSABLE_LIMIT) || (pkt->getLen() > UDP_PACKET_LEN_LIMIT))
	{
		// Send through TCP
		TCPSender *sender = new TCPSender(pkt, this);
		PR_QueueJob(pool, &thread_wrapper<TCPSender>, sender, PR_TRUE);
/*		PR_CreateThread(PR_USER_THREAD, 
				&thread_wrapper<TCPSender>, sender,
				PR_PRIORITY_LOW, PR_LOCAL_THREAD, 
				PR_JOINABLE_THREAD, 0);*/
	} else {
		// Send through UDP
		if (udpSock != NULL)
		{
			PRInt32 ret = PR_SendTo(udpSock, pkt->getData(), pkt->getLen(), 0, pkt->getPAddr(), 
					UDP_SEND_TIMEOUT);
			// Shall we release data?
			int len = pkt->getLen();
			delete pkt;
			if (ret == len)
				return PR_SUCCESS;
			else
			{
				LogMsg(LOG_DEBUG, "failed to send UDP packet.\n");
				ShowPRError();
				return PR_FAILURE;
			}
		}
	}
}


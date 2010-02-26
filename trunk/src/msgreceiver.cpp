#include "msgreceiver.h"
#include "threadwrap.h"
#include "config.h"
#include <prio.h>
#include <prthread.h>
#include <prnetdb.h>
#include "intercmd.h"
#include <prerror.h>

MsgReceiver::MsgReceiver(const PRNetAddr &a, int uport, int tport, Core *c)
{
	addr = a;
	udpPort = uport;
	tcpPort = tport;
	core = c;
	thread = NULL;
	udpSock = NULL;
	tcpSock = NULL;
}

PRStatus MsgReceiver::start()
{
	thread = PR_CreateThread(PR_SYSTEM_THREAD, &thread_wrapper<MsgReceiver>, this,
			PR_PRIORITY_HIGH, PR_LOCAL_THREAD, PR_JOINABLE_THREAD,
			0);
	if (!thread)
		return PR_FAILURE;
}

PRThread *MsgReceiver::getThread()
{
	return thread;
}

void MsgReceiver::run()
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
				int len = PR_RecvFrom(udpSock, udpBuffer, UDP_PACKET_LEN_LIMIT, 
						0, &remoteAddr, PR_INTERVAL_NO_TIMEOUT);
				if (len > 0)
					parsePacket(remoteAddr, len, udpBuffer);
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
				int ret = PR_AcceptRead(tcpSock, &tcpConn, &remoteAddr, &cmd, 2, TCP_ACCEPT_TIMEOUT);
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
						processConnection(tcpConn, remoteAddr, PR_ntohs(cmd));
					else
						PR_Close(tcpConn);
				}
			}
	}
	delete[] udpBuffer;
	PR_Close(udpSock);
	PR_Close(tcpSock);
}

void MsgReceiver::processConnection(PRFileDesc *conn, PRNetAddr *addr, PRInt16 cmd)
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
					parsePacket(*addr, len, data);
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
}

void MsgReceiver::parsePacket(const PRNetAddr &addr, int len, char *data)
{
	LogMsg(LOG_DEBUG, "lossable packet received. len: %d\n", len);
	if (len < 2)
		return;
	PRInt16 cmd = PR_ntohs(*((PRInt16 *)data));
	switch (cmd)
	{
		case INT_CMD_FIND_NEIGHBOUR:
			LogMsg(LOG_DEBUG, "someone is finding neighbour\n");
//			NeighbourReplyPacket nrp(core->getName());
//			sendMsg(addr, nrp.getLen(), nrp.getData());
			break;
		case INT_CMD_NEIGHBOUR_REPLY:
			LogMsg(LOG_DEBUG, "received reply from neighbour\n");
//			core->getUserManager()->parseNeighbourReply(addr, len, data);
			break;
		default:
			LogMsg(LOG_DEBUG, "unknown message: %d\n", cmd);
	}
}


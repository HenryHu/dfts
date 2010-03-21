// Last modified: 2010-03-21 00:02:24 henryhu
#ifndef __DTFS_CONFIG_H_
#define __DTFS_CONFIG_H_

extern int CLIENT_MANAGER_PORT;
extern int INTERCONNECT_PORT;
extern int CLIENT_MANAGER_BACKLOG_LEN;
extern int CLIENT_SERVICE_ERR_LIMIT;
extern int MSG_RECEIVER_BACKLOG_LEN;
extern int TCP_ACCEPT_TIMEOUT;
extern int TCP_HEADER_TIMEOUT;
extern int TCP_LOSSABLE_TIMEOUT;
extern int UDP_PACKET_LEN_LIMIT;
extern int TCP_PACKET_LEN_LIMIT;
extern int UDP_SEND_TIMEOUT;
extern int TCP_SEND_TIMEOUT;
extern int MSG_INIT_THREADS;
extern int MSG_MAX_THREADS;
extern int MSG_STACK_SIZE;

enum LogLevel {
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR
};

void LogMsg(LogLevel level, char *msg, ...);
void ShowPRError();

#endif // __DTFS_CONFIG_H_

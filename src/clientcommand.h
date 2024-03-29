// Last modified: 2010-03-21 23:15:48 henryhu
#ifndef __DTFS_CLIENTCOMMAND_H_
#define __DTFS_CLIENTCOMMAND_H_

extern const int CLI_CMD_COUNT;
extern const int CLIENT_COMMAND_LEN;

enum ClientCommand {
	CLI_CMD_UNKNOWN = -1,
	CLI_CMD_QUIT = 0,
	CLI_CMD_FIND_NEIGHBOUR,
	CLI_CMD_GET_NEIGHBOUR,
	CLI_CMD_GET_OTHER,
};

extern char* ClientCommandName[];

#endif // __DTFS_CLIENTCOMMAND_H_


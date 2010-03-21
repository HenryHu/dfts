#include "clientcommand.h"

const int CLIENT_COMMAND_LEN = 4;

char* ClientCommandName[] = {
	"quit",
	"find",
	"getn",
	"geto",
};

const int CLI_CMD_COUNT = sizeof(ClientCommandName) / sizeof(char*);

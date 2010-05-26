#include "config.h"
#include <stdarg.h>
#include <stdio.h>
#include <prerror.h>
#include <string.h>

void LogMsg(LogLevel level, char *msg, ...)
{
	switch (level) {
		case LOG_EXTEND:
			fprintf(stderr, "[extend] ");
			break;
		case LOG_INFO:
			fprintf(stderr, "[info] ");
			break;
		case LOG_ERROR:
			fprintf(stderr, "[error] ");
			break;
		case LOG_DEBUG:
			fprintf(stderr, "[debug] ");
			break;
		case LOG_WARN:
			fprintf(stderr, "[warning] ");
			break;
	}
	va_list arglist;
	va_start(arglist, msg);
	vfprintf(stderr, msg, arglist);
	va_end(arglist);
}

void ShowPRError()
{
	char *err = strerror(PR_GetOSError());
	LogMsg(LOG_ERROR, "Error %d: Native error %d: %s\n", PR_GetError(), PR_GetOSError(), err);
}

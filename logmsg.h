/*
   Header: logmsg.h

   	  Macros, functions and structures used for writing messages to a logfile.
   	  
   	  (c)2013-2015, Levien van Zon (levien@zonnetjes.net)
*/

#ifndef _P1PARSE_LOGMSG_H_
#define _P1PARSE_LOGMSG_H_

#include <stdio.h>


/* Logging macros */

#define LL_FATAL		1
#define LL_ERROR		2
#define LL_WARNING		3
#define LL_NORMAL		4
#define LL_VERBOSE		5
#define LL_DEBUG		6

#ifdef ENABLE_LOGGING
typedef struct msglogger_struct {
	
	char *logfile_name;
	FILE *logfile;
	int loglevel;
	
} messagelogger;

messagelogger logger;

static inline void init_msglogger() {
		logger.logfile_name = NULL;
		logger.logfile = stdout;
		logger.loglevel = LL_NORMAL;
}


#define logmsg(level, format, args...) { \
	if (level <= logger.loglevel && logger.logfile) { \
		if (level == LL_WARNING) \
			fprintf(logger.logfile, "WARNING: "); \
		else if (level == LL_ERROR) \
			fprintf(logger.logfile, "ERROR: "); \
		else if (level == LL_FATAL) \
			fprintf(logger.logfile, "FATAL ERROR: "); \
		fprintf(logger.logfile, format, ##args); \
		fflush(logger.logfile); \
	} \
}
#else
#define logmsg(level, format, args...)
#endif

#endif //!_P1PARSE_LOGMSG_H_

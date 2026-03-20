// -- core engine logger header

#pragma once

#include "def.h"

// enable/disable log defines
#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// disable debug/trace logs for release
#if MRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

// enum representing log_level from trace to fatal
typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN  = 2,
    LOG_LEVEL_INFO  = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8 initialize_logging();
void shutdown_logging();

MAPI void log_output(log_level level, const char* message, ...);

// logs a fatal-level message
#define MFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef MERROR
// logs an error-level message
#define MERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// logs a warning-level message
#define MWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define MWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// logs an info-level message
#define MINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define MINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// logs a debug-level message
#define MDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define MDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// logs a trace-level message
#define MTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define MTRACE(message, ...)
#endif
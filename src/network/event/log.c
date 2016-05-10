#include "log.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#define TIME_LENGTH 21

static void log_format(const char* tag, const char *msg, va_list args)
{
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    static char date[TIME_LENGTH];
    strftime(date, sizeof(date) - 1, "%Y-%m-%d %H:%M:%S", now);
    printf("%s [%s] ", date, tag);
    vprintf(msg, args);
    printf("\n\n");
}


void (log_error)(const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    log_format("ERROR", msg, args);
    va_end(args);
}

void (log_info)(const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    log_format("INFO ", msg, args);
    va_end(args);
}

void (log_debug)(const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    log_format("DEBUG", msg, args);
    va_end(args);
}



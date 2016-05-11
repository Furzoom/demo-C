#include "log.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#define TIME_LENGTH 20

static const char *LOG_FILE = "trace.log";

static FILE *file = NULL;

static void log_format(const char* tag, const char *msg, va_list args)
{
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    static char date[TIME_LENGTH];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", now);

    if (!file)
    {
        file = fopen(LOG_FILE, "a");
    }

    fprintf(file, "%s [%s] ", date, tag);
    vfprintf(file, msg, args);
    fprintf(file, "\n\n");
    fflush(file);
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



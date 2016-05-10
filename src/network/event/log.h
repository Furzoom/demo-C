#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <string.h>
#define MSGBUFFER_LENGTH 4096
#define LINEBUFFER_LENGTH 1024

#define log_error(msg, ...) \
{ \
    char buff[MSGBUFFER_LENGTH] = {0}; \
    snprintf(buff, sizeof(buff), "FILE = %s LINE = %d\n", __FILE__, __LINE__); \
    int len = strlen(buff); \
    strncat(buff + len, msg, sizeof(buff) - len - 1); \
    log_error(buff, ##__VA_ARGS__); \
}

#define log_info(msg, ...) \
{ \
    char buff[MSGBUFFER_LENGTH] = {0}; \
    snprintf(buff, sizeof(buff), "FILE = %s LINE = %d\n", __FILE__, __LINE__); \
    int len = strlen(buff); \
    strncat(buff + len, msg, sizeof(buff) - len - 1); \
    log_info(buff, ##__VA_ARGS__); \
}

#define log_debug(msg, ...) \
{ \
    char buff[MSGBUFFER_LENGTH] = {0}; \
    snprintf(buff, sizeof(buff), "FILE = %s LINE = %d\n", __FILE__, __LINE__); \
    int len = strlen(buff); \
    strncat(buff + len, msg, sizeof(buff) - len - 1); \
    log_debug(buff, ##__VA_ARGS__); \
}

#ifdef __cplusplus
extern "C" {
#endif

void (log_error)(const char* msg, ...);
void (log_info)(const char* msg, ...);
void (log_debug)(const char* msg, ...);

#ifdef __cplusplus
}
#endif

#endif // LOG_H

#ifndef __UNP_H
#define __UNP_H

#include "error.h"
#include <sys/types.h>      /* basic system data types */
#include <sys/socket.h>     /* basic socket definitions */
#include <sys/time.h>       /* timeval{} for  select() */
#include <time.h>           /* timespec{} for pselect() */
#include <netinet/in.h>     /* sockadd_in{} and other internet defines */
#include <arpa/inet.h>      /* inet{3} functions */
#include <errno.h>
#include <fcntl.h>          /* for nonblocking */
#include <netdb.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>       /* for S_xxx file mode constants */
#include <sys/uio.h>        /* for iovec{} and readv/writev */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>         /* for Unix domain sockets */

#define recv(a, b, c, d)    recvfrom(a, b, c, d, 0, 0)
#define send(a, b, c, d)    sendto(a, b, c, d, 0, 0)

#ifndef HAVE_BZERO
#define bzero(ptr, n)       memset(ptr, 0, n)
#endif

#define LISTENQ 1024        /* 2nd argument to listen */
#define MAXLINE 4096        /* max text line lenght */
#define BUFFSIZE 4096       /* buffer size for reads and writes */
#define SERV_PORT 9877      /* server port */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) /* creat file mode */

ssize_t readn(int filedes, void *buff, size_t nbytes);
ssize_t writen(int filedes, const void *buff, size_t nbytes);
ssize_t readline(int filedes, void *buff, size_t naxlen);

#endif // __unp_h

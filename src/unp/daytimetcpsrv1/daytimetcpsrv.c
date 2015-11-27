#include "unp.h"
#include <time.h>

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;
    char buf[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        err_sys("bind error");
    }

    if (listen(listenfd, LISTENQ) < 0)
    {
        err_sys("listen error");
    }

    while (1)
    {
        len = sizeof(cliaddr);

        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) < 0)
        {
            err_ret("connfd error");
            continue;
        }
        printf("connection from %s, port %d\n",
                inet_ntop(AF_INET, &cliaddr.sin_addr, buf, sizeof(buf)),
                ntohs(cliaddr.sin_port));
        ticks = time(NULL);
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
        if (write(connfd, buf, strlen(buf)) < 0)
        {
            err_ret("write error");
        }

        if (close(connfd) < 0)
        {
            err_ret("close error");
        }
    }
    if (close(listenfd) < 0)
        err_ret("close error");

    return 0;
}


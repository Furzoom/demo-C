/**********************************************************************
 * Filename      : tcpserv01.c
 * Description   : tcpserv01.c
 * Author        : Furzoom
 * Email         : mn@furzoom.com
 * Date          : 2015-11-17
 * Last modified : 2015-11-27
 * Version       : 0.0.1
 **********************************************************************/
#include "unp.h"

typedef void Sigfunc(int);

Sigfunc *Signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }
    else
    {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
        return (SIG_ERR);
    return oact.sa_handler;
}

void sig_chld(int signo)
{
    pid_t   pid;
    int     stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
    {
        printf("child %d terminated\n", pid);
    }
    return;
}

void str_echo(int sockfd)
{
    long arg1, arg2;
    ssize_t n;
    char    buf[MAXLINE];

    do {
        if ((n = readline(sockfd, buf, MAXLINE)) == 0)
        {
            return; // connection closed by peer edn
        }
        if (sscanf(buf, "%ld%ld", &arg1, &arg2) == 2)
        {
            snprintf(buf, sizeof(buf), "%ld\n", arg1 + arg2);
        }
        else
        {
            snprintf(buf, sizeof(buf), "input error\n");
        }
        n = strlen(buf);
        writen(sockfd, buf, n);
    } while (1);
}

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t chilen;
    struct sockaddr_in servaddr, cliaddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        err_sys("bind error");
    }

    if (listen(listenfd, LISTENQ) < 0)
    {
        err_sys("listen error");
    }

    Signal(SIGCHLD, sig_chld);

    while (1)
    {
        chilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &chilen)) < 0)
        {
            if (errno == EINTR)
            {
                err_ret("accept");
                continue;       // back to while
            }
            else
            {
                err_sys("accept error");
            }
        }

        if ((childpid = fork()) == 0)
        {   // child process
            if (close(listenfd) < 0)    // close listening socket
                err_ret("In child close error");
            str_echo(connfd);
            exit(0);
        }

        if (close(connfd) < 0)
            err_ret("close error");

    }
    if (close(listenfd) < 0)
        err_ret("close listenfd error");

    return 0;
}




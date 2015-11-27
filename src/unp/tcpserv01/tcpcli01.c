/**********************************************************************
 * Filename      : tcpcli01.c
 * Description   : tcpcli01.c
 * Author        : Furzoom
 * Email         : mn@furzoom.com
 * Date          : 2015-11-17
 * Last modified : 2015-11-27
 * Version       : 0.0.1
 **********************************************************************/

#include "unp.h"

void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];
    while (fgets(sendline, MAXLINE, fp) != NULL)
    {
        writen(sockfd, sendline, strlen(sendline));
        if (readline(sockfd, recvline, MAXLINE) == 0)
            err_quit("str_cli: server terminated prematurely");
        fputs(recvline, stdout);
    }
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    int s;

    if (argc != 2)
        err_quit("usage: %s <IPaddress>\n", argv[0]);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    if ((s = inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr)) == -1)
        err_sys("No supported address family");
    else if (s == 0)
        err_quit("error %s", argv[1]);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("error connect");

    str_cli(stdin, sockfd);

    if (close(sockfd) < 0)
        err_ret("error close");

    return 0;
}


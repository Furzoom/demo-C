/*
 * setsockopt_reuseaddr.cpp - By furzoom @ Feb 03, 2016
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in addr;

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);
    int reuse = 1;
    // reuse address
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    int ret = bind(sock, (struct sockaddr*)&addr, sizeof(addr));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    struct sockaddr_in client;
    socklen_t client_length = sizeof(client);
    int connfd = accept(sock, (struct sockaddr*)&client, &client_length);
    if (connfd != -1)
    {
        char buf[BUF_SIZE];
        recv(connfd, buf, BUF_SIZE - 1, 0);
        puts(buf);
        recv(connfd, buf, BUF_SIZE - 1, 0);
        puts(buf);
        recv(connfd, buf, BUF_SIZE - 1, 0);
        puts(buf);
        recv(connfd, buf, BUF_SIZE - 1, 0);
        puts(buf);
        close(connfd);
    }

    close(sock);
    return 0;
}



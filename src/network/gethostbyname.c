#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char hostname[] = "baidu.com";
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 0;
    }
    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "gethostbyname error\n");
        return 1;
    }
    printf("h_name: %s\n", host->h_name);
    //printf("h_addr: %s\n", inet_ntoa(*((struct in_addr *)host->h_addr)));
    int i = 0;
    printf("h_aliases:\n");
    while (host->h_aliases[i] != NULL)
    {
        printf("\th_aliase: %s\n", host->h_aliases[i]);
        i++;
    }
    printf("h_addrtype: %s\n", host->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");
    printf("h_length: %d\n", host->h_length);

    i = 0;
    printf("h_addr_list:\n");
    while (host->h_addr_list[i] != NULL)
    {
        
        printf("\taddr: %s\n", inet_ntoa(*((struct in_addr *)(host->h_addr_list[i]))));
        i ++;
    }
    
    return 0;
}


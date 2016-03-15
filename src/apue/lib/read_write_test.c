#include "unp.h"

int main()
{
    char buff[MAXLINE];
    ssize_t n = readn(STDIN_FILENO, buff, 10);
    printf("\n%ld\n", n);
    puts(buff);
    return 0;
}

/*
 * read from stdin and write to stdout
 */
#include "unp.h"

int main()
{
    ssize_t n;
    char buf[BUFFSIZE];
    
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");
    }
    if (n < 0)
        err_sys("read error");
    return 0;
}


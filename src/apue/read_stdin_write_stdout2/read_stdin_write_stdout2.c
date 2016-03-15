/*
 * read from stdin and write to stdout
 */
#include "unp.h"

int main()
{
    int c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("stdout error");
    if (ferror(stdin))
        err_sys("stdin error");

    return 0;
}


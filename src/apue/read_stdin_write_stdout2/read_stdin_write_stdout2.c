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
    if (feof(stdin))
        printf("EOF stdin\n");
    printf("stdin fd %u\n", fileno(stdin));
    printf("stdout fd %u\n", fileno(stdout));
    printf("stderr fd %u\n", fileno(stderr));

    return 0;
}


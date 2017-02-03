#include "unp.h"

static void output_char(char * str)
{
    char *ptr;
    setbuf(stdout, NULL); // set unbuffered
    for (ptr = str; *ptr != '\0'; ptr++)
        fputc(*ptr, stdout);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        output_char("output from child\n");
    }
    else
    {
        output_char("output from parent\n");
    }
    return 0;
}

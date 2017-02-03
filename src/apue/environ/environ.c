#include <stdio.h>

int main(int argc, char *argv[])
{
    extern char **environ;
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf("environ[%d] = %s\n", i, environ[i]);
    return 0;
}


#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    char *newargv[] = {NULL, "hello", "world", NULL};
    char *newenv[] = {NULL};

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        return -1;
    }
    newargv[0] = argv[1];

    execve(argv[1], newargv, newenv);
    perror("execv");
    return 0;
}

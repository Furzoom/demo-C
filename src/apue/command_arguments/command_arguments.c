#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
        printf("argv[%d] is %s\n", i, argv[i]);

    printf("Use argv[argc] == NULL\n");
    for (i = 0; argv[i] != NULL; i++)
        printf("argv[%d] is %s\n", i, argv[i]);

    return 0;
}

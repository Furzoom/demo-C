#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    const char *value;
    if ((value = getenv("TZ")) != NULL)
        printf("TZ = %s\n", value);
    else
        printf("TZ not defiend\n");

    if ((value = getenv("PWD")) != NULL)
        printf("PWD = %s\n", value);
    else
        printf("PWD not defiend\n");
    return 0;
}

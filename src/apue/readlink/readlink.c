#include "unp.h"

int main()
{
    const char pathname[] = "foo";
    char buf[128];
    ssize_t len = readlink(pathname, buf, sizeof(buf) - 1);
    printf("Reading foo...\n");
    if (len == -1)
    {
        err_sys("readlink error");
    }

    buf[len] = '\0';
    printf("link content: %s\n", buf);
    return 0;
}


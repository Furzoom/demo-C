#include "unp.h"

int main(int argc, char *argv[])
{
    const char *pathname = "test";
    printf("mkdir...\n");
    if (mkdir(pathname, S_IRUSR | S_IWUSR | S_IXUSR) < 0)
        err_sys("mkdir error");
    sleep(2);
    printf("rmdir...\n");
    if (rmdir(pathname) < 0)
        err_sys("rmdir error");

    printf("Done\n");
    return 0;
}

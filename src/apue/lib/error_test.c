#include "error.h"

void test(void);

int main(int argc, char **argv)
{
    test();
    return 0;
}

void test(void)
{
//    err_ret("err_ret %s", "yes");
//    err_sys("err_sys");
//    err_dump("err_dump");
//    err_msg("err_msg");
    err_quit("err_quit");
}


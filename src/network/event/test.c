#include <stdio.h>
#include "log.h"

int main()
{
    log_error("Not found");
    log_info("ret = %d", 10);
    log_debug("a = 10");
    log_error("ret = %d", 10);
    return 0;
}

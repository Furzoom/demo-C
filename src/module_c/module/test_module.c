/*
 * test_module.c - By furzoom @ Jan 07, 2016
 */

#include "module.h"
#include <stdio.h>
#include <assert.h>

void test()
{
    MODULE *module = Create();
    assert(1 == Serve(module));
    assert(2 == Serve(module));
    Destroy(module);
    printf("TEST MODULE SUCCESS\n");
}

int main()
{
    test();
    return 0;
}



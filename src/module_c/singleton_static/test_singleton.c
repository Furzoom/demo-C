/*
 * test_singleton.c - By furzoom @ Jan 07, 2016
 */

#include "singleton.h"
#include <stdio.h>
#include <assert.h>

void test()
{
    SINGLETON *instance1 = GetInstance();
    SINGLETON *instance2 = GetInstance();
    assert(instance1 == instance2);
    assert(1 == Serve(instance1));
    assert(2 == Serve(instance2));
    assert(1 == 2);
    printf("TEST SINGLETON SUCCESS!\n");
}

int main()
{
    test();
    return 0;
}


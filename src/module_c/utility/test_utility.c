/*
 * test_utility.c - By furzoom @ Jan 07, 2016
 */

#include "utility.h"
#include <assert.h>
#include <stdio.h>

void test()
{
    assert(1 == Serve1());
    assert(10 == Serve2(10));
    printf("TEST UTILITY SUCCESS!\n");
}

int main()
{
    test();
    return 0;
}


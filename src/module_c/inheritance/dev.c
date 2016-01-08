/*
 * dev.c - By furzoom @ Jan 07, 2016
 */

#include "dev.h"
#include <assert.h>
#include <string.h>

void Init(struct DEV *dev, const struct I_DEV *itf)
{
    assert(dev != NULL);
    memset(dev, 0, sizeof(*dev));
    dev->itf = itf;
    dev->Method1 = Method1;
}

void Destroy(struct DEV *self)
{
    if (self != NULL)
        free(self);
}

void Method1(struct DEV *self)
{
    printf("I'm method1 in %s\n", __FILE__);
}


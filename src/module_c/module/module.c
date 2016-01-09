/*
 * module.c - By furzoom @ Jan 07, 2016
 */

#include "module.h"
#include <stdlib.h>

struct _MODULE
{
    int privateData;
};

static int ImplementService(MODULE *self)
{
    return ++self->privateData;
}

MODULE *Create(void)
{
    MODULE *module = (MODULE *)malloc(sizeof(MODULE));
    module->privateData = 0;
    return module;
}

void Destroy(MODULE *self)
{
    if (self != NULL)
        free(self);
}

int Serve(MODULE *self)
{
    return (self != NULL) ? ImplementService(self) : 0;
}


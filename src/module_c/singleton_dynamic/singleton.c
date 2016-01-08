/*
 * singleton.c - By furzoom @ Jan 07, 2016
 */

#include "singleton.h"
#include <stdlib.h>
#include <assert.h>

struct _SINGLETON
{
    char privateData[0];
};

static SINGLETON *gInstance = NULL;

static SINGLETON *Create(void)
{
    SINGLETON *singleton = (SINGLETON *)malloc(sizeof(SINGLETON));
    assert(singleton != NULL);
    return singleton;
}

SINGLETON *GetInstance(void)
{
    if (NULL == gInstance)
    {
        gInstance = Create();
    }
    return gInstance;
}

void Destroy(SINGLETON *self)
{
    if (self != NULL && self == gInstance)
    {
        free(gInstance);
        gInstance = NULL;
    }
}


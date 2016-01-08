/*
 * singleton.c - By furzoom @ Jan 07, 2016
 */

#include "singleton.h"
#include <string.h>

struct _SINGLETON
{
    char privateData;
};

static SINGLETON gInstance = {0};

static void Singleton_init(void)
{
    memset(&gInstance, 0, sizeof(SINGLETON));
}

SINGLETON *GetInstance(void)
{
    Singleton_init();
    return &gInstance;
}

int Serve(SINGLETON *self)
{
    return ++self->privateData;
}


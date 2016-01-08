/*
 * singleton.h - By furzoom @ Jan 07, 2016
 */

#ifndef __SINGLETON__
#define __SINGLETON__

struct _SINGLETON;
typedef struct _SINGLETON SINGLETON;

SINGLETON *GetInstance(void);
int Serve(SINGLETON *self);

#endif // __STINGLETON__


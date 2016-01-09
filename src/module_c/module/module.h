/*
 * module.h - By furzoom @ Jan 07, 2016
 */

#ifndef __MODULE__
#define __MODULE__

struct _MODULE;
typedef struct _MODULE MODULE;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

MODULE *Create(void);
void Destroy(MODULE *self);
int Serve(MODULE *self);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MODULE__
  


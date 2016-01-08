/*
 * dev.h - By furzoom @ Jan 07, 2016
 */

#ifndef __DEV__
#define __DEV__

struct I_DEV {
    int (*Add)(struct DEV *, int para);
    int (*Delete)(struct DEV *, int para);
    int (*Query)(struct DEV *, int para);
    int (*Reset)(struct DEV *, int para);
};

struct DEV {
    void (*Destroy)(struct DEV *);
    void (*Method1)(struct DEV *);
    void (*Method2)(struct DEV *);
    const struct I_DEV *itf;
    void *privateData;
};

void Init(struct DEV *dev, const struct I_DEV *itf);
void Destroy(struct DEV *self);
void Method1(struct DEV *self);

#endif // __DEV__

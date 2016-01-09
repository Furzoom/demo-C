/*
 * inheritance_utils.h - By furzoom @ Jan 07, 2016
 */

#undef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) \
    ((type *)((char *)(address) - (unsigned long)(&((type *)0)->field)))

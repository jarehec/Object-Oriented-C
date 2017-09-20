#ifndef NEW_H
#define NEW_H
#include <stdarg.h>
#include <assert.h>
void *new(const void *type, ...);
void delete(void *item);

#endif

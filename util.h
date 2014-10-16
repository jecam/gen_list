#include <stdio.h>
#include <stdlib.h>

#ifndef UTIL
#define UTIL

typedef enum bool {
    false, true
}bool;

void* safe_malloc(size_t size);

#endif

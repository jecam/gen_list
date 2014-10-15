#include <stdio.h>

typedef enum bool {
    false, true
}bool;

void* safe_malloc(size_t size) {
    void* memblock = malloc(size);
    if (!memblock){
        fprintf(stderr, "Memory could not be allocated, aborting program.\n");
        exit(0);
    }
    return memblock;
}

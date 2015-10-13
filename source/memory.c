/* memory.c
 * By Jonathon McDonald
 */
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* Allocates `size` amount of bytes in memory and returns a pointer. */
void* xmalloc(size_t size)
{
    void* ptr = malloc(size);
    if (NULL == ptr) {
        fputs("xmalloc failed", stderr);
        exit(EXIT_FAILURE);
    }

    return ptr;
}

/* Frees the allocated memory. Outputs a warning if the pointer is null. */
void xfree(void* ptr)
{
    if (NULL == ptr) {
        fputs("xfree expects a valid pointer, but was given NULL.", stderr);
    }

    free(ptr);
}

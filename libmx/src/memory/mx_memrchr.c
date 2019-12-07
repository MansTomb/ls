#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *us = (void *)s;

    if (!us || !n)
        return NULL;

    for (size_t i = n - 1; i; --i)
        if (us[i] == c)
            return (void *)(us + i);

    return *us == c ? (void *)s : NULL;
}
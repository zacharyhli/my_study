#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/libkern.h>
#include <sys/malloc.h>

char *strdup(const char *string, struct malloc_type *type)
{
    size_t len;
    char *copy;

    len = strlen(string) + 1;
    copy = malloc(len, type, M_WAITOK);
    bcopy(string, copy, len);

    return copy;
}

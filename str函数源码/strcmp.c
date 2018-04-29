#include <sys/cdefs.h>
#include <sys/libkern.h>

int strcmp(s1, s2)
{
    const char *s1, *s2;

    while(*s1 == *s2++)
        if(*s1++ == 0)
            return 0;

    return (*(const unsigned cahr *)s1 - *(const unsigned char *)(s2 - 1));
}

#include <sys/cdefs.h>
#include <sys/libkern.h>

char *strcpy(char *_restrict to, const char *_restrict from)
{
    char *save = to;

    for(; (*to = *from) != 0; ++from, ++to);

    return (save);
}

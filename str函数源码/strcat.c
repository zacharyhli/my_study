#include <sys/cdefs.h>
#include <sys/libkern.h>

char *strcat(char *_restrict s, const char *_restrict append)
{
    char *save = s;

    for(; *s; ++s);
    while((*s++ = *append++) != 0);

    return save;
}

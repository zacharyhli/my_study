#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/libkern.h>

char *strchr(const char *p, int ch)
{
    union{
        const char *cp;
        char *p;
    }u;

    u.cp = p;
    for(;; ++u.p){
        if(*u.p == ch)
            return u.p;
        if(*u.p == '\0')
            return NULL;
    }
}

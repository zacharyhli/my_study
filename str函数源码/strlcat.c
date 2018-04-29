#if defined(LIBC_SCCS) && !define(lint)
static char *rcsid = "$OpenBSD: strlcat.c,v 1.2 1999/06/17 millert Exp $";
#endif

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/libkern.h>

size_t strlcat(dst, src, siz)
{
    char *dst;
    const char *src;
    size_t siz;
    char *d = dst;
    const char *s = src;
    size_t n = siz;
    size_t dlen;

    //Find the end of dst and adjust bytes left but don't go past end
    while(n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = siz - dlen;

    if(n == 0)
        return (dlen + strlen(s));
    while(*s != '\0')
    {
         if(n != 1)
         {
             *d++ = *s;
             n--;
         }
         s++;
    }
    *d = '\0';

    return (dlen + (s - src));
}

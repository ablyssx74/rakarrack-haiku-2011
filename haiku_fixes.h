#if defined(__x86_64__)
#ifndef HAIKU_FIXES_H
#define HAIKU_FIXES_H

#include <cstring>
#include <cstdlib>

#ifdef __HAIKU__
// strsep() lives in libroot (declared by <bsd/string.h>). The private
// static-inline copy this header used to carry now conflicts with that
// declaration and leaks a global strsep into every object file.
#include <bsd/string.h>
#endif

#endif
#elif defined(__i386__)
    // Do notta
#endif



/*#ifndef HAIKU_FIXES_H
#define HAIKU_FIXES_H
#include <cstring>
static inline char *strsep(char **stringp, const char *delim) {
    char *s; const char *spanp; int c, sc; char *tok;
    if ((s = *stringp) == NULL) return (NULL);
    for (tok = s;;) {
        c = *s++; spanp = delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0) s = NULL; else s[-1] = 0;
                *stringp = s; return (tok);
            }
        } while (sc != 0);
    }
}
#endif
*/

#ifndef IMPORTS_H
#define IMPORTS_H

#ifdef __NetBSD__
  #ifndef UNIX
    #define UNIX
  #endif
#endif

#ifdef __unix
  #ifdef UNIX
    #define UNIX 
  #endif
#endif

#ifdef __linux
  #ifdef UNIX
    #define UNIX 
  #endif
#endif

#ifndef UNIX
  #ifndef plan9
    #error "Either, 'unix' or 'plan9' must be defined" 
  #endif
#endif

#ifdef unix
  #ifndef _BSD_SOURCE
    #define _BSD_SOURCE
  #endif
  #ifndef __FreeBSD__
    #ifndef __NetBSD__
      #ifndef _POSIX_SOURCE
        #define _POSIX_SOURCE
        #define _POSIX_C_SOURCE 200112L
      #endif
      #ifndef _XOPEN_SOURCE
        #define _XOPEN_SOURCE 500
      #endif
    #endif
  #endif
#endif

#ifdef plan9
  #include <u.h>
  #include <libc.h>
  #include <stdio.h>
  #include <ctype.h>
  #define NO_SIGNALS
  #define signal(sig, fn)
  #define exit(x) exits((x)? "error": NULL)
  #define ptrdiff_t int
#endif

#ifdef unix
  #include <stdlib.h>
  #include <stddef.h>
  #include <stdio.h>
  #include <string.h>
  #include <ctype.h>
  #ifdef NO_SIGNALS
  #define signal(sig, fn)
  #else
  #include <signal.h>
  #ifndef SIGQUIT
    /* MinGW does not define SIGQUIT */
    #define SIGQUIT SIGINT
  #endif
  #endif
#endif

/*
 * Tell later MSC compilers to let us use the standard CLIB API.
 * Blake McBride < b l a k e  at  m c b r i d e . n a m e >
 */

#ifdef _MSC_VER
  #if _MSC_VER > 1200
    #ifndef _CRT_SECURE_NO_DEPRECATE
      #define _CRT_SECURE_NO_DEPRECATE
    #endif
  #endif
  #ifndef _POSIX_
    #define _POSIX_
  #endif
#endif

#ifndef DEFAULT_LIBRARY_PATH
  #define DEFAULT_LIBRARY_PATH \
    "."				\
    ":lib"				\
    ":ext"				\
    ":contrib"			\
    ":~/.s9fes"			\
    ":/usr/local/share/s9fes"
#endif

#endif // IMPORTS_H
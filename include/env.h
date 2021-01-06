#ifndef ENV_H
#define ENV_H

#include "imports.h"

#ifndef INITIAL_SEGMENT_SIZE
  #define INITIAL_SEGMENT_SIZE 32768
#endif

#define TOKEN_LENGTH 1024
#define MAX_PORTS 32
#define MAX_IO_DEPTH 65536
#define HASH_THRESHOLD 5
#define MAX_CALL_TRACE 100

#define DEFAULT_LIMIT_KN 12392

#define cell ptrdiff_t

/* 64-bit emulation on 32 bit system; DO NOT USE */
#ifdef EMULATE_64
  #undef BITS_PER_WORD_32
  #define BITS_PER_WORD_64
  #undef cell
  #define cell long long
  #define labs(x)  llabs(x)
  #define atol(x)  atoll(x)
#endif

/* Pick one ... */
/* #define BITS_PER_WORD_64 */
/* #define BITS_PER_WORD_32 */
/* #define BITS_PER_WORD_16 */

/* ... or assume a reasonable default */
#ifndef BITS_PER_WORD_16
  #ifndef BITS_PER_WORD_32
    #ifndef BITS_PER_WORD_64
      #define BITS_PER_WORD_32
    #endif
  #endif
#endif


#endif // ENV_H
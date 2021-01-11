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

#ifdef BITS_PER_WORD_64
  #define DIGITS_PER_WORD 18
  #ifdef EMULATE_64
    #define INT_SEG_LIMIT 1000000000000000000LL
  #else
    #define INT_SEG_LIMIT 1000000000000000000L
  #endif
  #define MANTISSA_SEGMENTS 1
#else
  #ifdef BITS_PER_WORD_32
    #define DIGITS_PER_WORD 9 
    #define INT_SEG_LIMIT 1000000000L
    #define MANTISSA_SEGMENTS 2
  #else
    #ifdef BITS_PER_WORD_16
      #define DIGITS_PER_WORD 4
      #define INT_SEG_LIMIT 10000
      #define MANTISSA_SEGMENTS 3
    #else
      #error "BITS_PER_WORD_* undefined (this should not happen)"
    #endif
  #endif
#endif

#define MANTISSA_SIZE (MANTISSA_SEGMENTS * DIGITS_PER_WORD)



#endif // ENV_H
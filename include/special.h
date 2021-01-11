#ifndef SPECIAL_H
#define SPECIAL_H 

#include "types.h"

#define special_value_p(x) ((x) < 0)
#define NIL (-1)
#define TRUE (-2)
#define FALSE (-3)
#define END_OF_FILE (-4)
#define UNDEFIEND (-5)
#define UNSPECIFIC (-6)
#define NAN (-7)
#define DOT (-8)
#define RPAREN (-9)
#define RBRACK (-10)
#define NOEXPR (-11)

// Types are also special objects
// included in types.h

#endif // SPECIAL_H
#ifndef TYPES_H
#define TYPES_H 

// Types are also special objects
// T_NONE indicates "no specific type" in type checking. T_PAIR_OR_NIL matches either a pair or ().

// T_PRIMITIVE is used to mark primitive procedures and T_CONTINUATION marks continuations internally.
// to the type checker, these constants are synonyms of T_PROCEDURE

// T_SYNTAX marks macros.

#define T_NONE (-20)
#define T_BOOLEAN (-21)
#define T_CHAR (-22)
#define T_INPUT_PORT (-23)
#define T_INTEGER (-24)
#define T_OUTPUT_PORT (-25)
#define T_PAIR (-26)
#define T_PAIR_OR_NIL (-27)
#define T_PRIMITIVE (-28)
#define T_PROCEDURE (-29)
#define T_REAL (-30)
#define T_STRING (-31)
#define T_SYMBOL (-32)
#define T_SYNTAX (-33)
#define T_VECTOR (-34)
#define T_CONTINUATION (-35)

#endif // TYPES_H
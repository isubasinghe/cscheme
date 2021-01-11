#include "env.h"
#include "special.h"

#ifndef INTERNALS_H
#define INTERNALS_H

#define ATOM_TAG 0x01
#define MARK_TAG 0x02
#define STATE_TAG 0x04
#define VECTOR_TAG 0x08
#define PORT_TAG 0x10
#define USED_TAG 0x20
#define LOCK_TAG 0x40
#define CONST_TAG 0x80

enum EVAL_STATES {
  EV_ATOM, /* Evaluating atom */
  EV_ARGS, /* Evaluating arguemnt list */
  EV_BETA, /* Evaluating proocedure body */
  EV_IF_PRED, /* Evaluating predicate of if */ 
  EV_SET_VAL, /* Evaluating value of SET! and DEFINE */ 
  EV_MACRO,   /* Evaluating value of DEFINE-SYNTAX */ 
  EV_BEGIN,  /* Evaluating expressions of BEGIN */
  EV_AND, /* Evaluating arguments of AND */ 
  EV_OR, /* Evaluating arguments of OR */
  EV_COND  /* Evaluating arguments of COND */
};

// Binding structure

#define make_binding(v, a) (cons((v), (a)))
#define binding_box(x) (x)
#define binding_value(x) (x)
#define box_value(x) (cdr(x))

// Special objects
// included in special.h

struct PrimitiveProcedure {
  char *name;
  cell (*handler) (cell expr);
  int min_args;
  int max_args; /* -1 = variadic */
  int arg_types[3];
};

#define PRIM_SEG_SIZE 256 

#ifndef EXTERN
  #define EXTERN extern
#endif

EXTERN int ConsSegmentSize,
            VecSegmentSize;
EXTERN int ConsPoolSize,
            VecPoolSize;

EXTERN cell *Car,
            *Cdr;

EXTERN char *Tag;

EXTERN cell *Vectors;

EXTERN cell FreeList;
EXTERN cell FreeVecs;

#endif // INTERNALS_H
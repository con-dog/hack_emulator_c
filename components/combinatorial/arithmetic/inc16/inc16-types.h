#ifndef INC16_TYPES_H
#define INC16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Inc16_Input
{
  bool in[WORD_SIZE];
} Inc16_Input;

typedef struct Inc16_Output
{
  bool out[WORD_SIZE];
} Inc16_Output;

typedef struct Inc16
{
  Inc16_Input input;
  Inc16_Output output;
} Inc16;

#endif
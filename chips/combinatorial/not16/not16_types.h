#ifndef NOT16_TYPES_H
#define NOT16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct
{
  bool in[WORD_SIZE];
} Not16_Input;

typedef struct
{
  bool out[WORD_SIZE];
} Not16_Output;

typedef struct
{
  Not16_Input input;
  Not16_Output output;
} Not16;

#endif
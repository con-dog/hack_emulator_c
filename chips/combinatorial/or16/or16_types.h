#ifndef OR16_TYPES_H
#define OR16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Or16_Input
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
} Or16_Input;

typedef struct Or16_Output
{
  bool out[WORD_SIZE];
} Or16_Output;

typedef struct Or16
{
  Or16_Input input;
  Or16_Output output;
} Or16;

#endif
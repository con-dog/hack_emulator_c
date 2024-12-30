#ifndef OR_8WAY_TYPES_H
#define OR_8WAY_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Or_8way_Input
{
  bool in[BYTE_SIZE];
} Or_8way_Input;

typedef struct Or_8way_Output
{
  bool out;
} Or_8way_Output;

typedef struct Or_8way
{
  Or_8way_Input input;
  Or_8way_Output output;
} Or_8way;

#endif
#ifndef OR_8_WAY_TYPES_H
#define OR_8_WAY_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Or_8_Way_Input
{
  bool in[BYTE_SIZE];
} Or_8_Way_Input;

typedef struct Or_8_Way_Output
{
  bool out;
} Or_8_Way_Output;

typedef struct Or_8_Way
{
  Or_8_Way_Input input;
  Or_8_Way_Output output;
} Or_8_Way;

#endif
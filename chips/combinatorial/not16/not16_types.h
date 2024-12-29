#ifndef NOT16_TYPES_H
#define NOT16_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool in[16];
} Not16_Input;

typedef struct
{
  bool out[16];
} Not16_Output;

typedef struct
{
  Not16_Input input;
  Not16_Output output;
} Not16;

#endif
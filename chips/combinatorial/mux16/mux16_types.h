#ifndef MUX16_TYPES_H
#define MUX16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Mux16_Input
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
  bool sel;
} Mux16_Input;

typedef struct Mux16_Output
{
  bool out[WORD_SIZE];
} Mux16_Output;

typedef struct Mux16
{
  Mux16_Input input;
  Mux16_Output output;
} Mux16;

#endif
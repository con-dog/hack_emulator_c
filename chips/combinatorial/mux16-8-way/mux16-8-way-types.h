#ifndef MUX16_8_WAY_TYPES_H
#define MUX16_8_WAY_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Mux16_8_Way_Input
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
  bool c[WORD_SIZE];
  bool d[WORD_SIZE];
  bool e[WORD_SIZE];
  bool f[WORD_SIZE];
  bool g[WORD_SIZE];
  bool h[WORD_SIZE];

  bool sel[3];
} Mux16_8_Way_Input;

typedef struct Mux16_8_Way_Output
{
  bool out[WORD_SIZE];
} Mux16_8_Way_Output;

typedef struct Mux16_8_Way
{
  Mux16_8_Way_Input input;
  Mux16_8_Way_Output output;
} Mux16_8_Way;

#endif
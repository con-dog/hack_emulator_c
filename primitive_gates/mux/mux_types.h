#ifndef MUX_TYPES_H
#define MUX_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool a;
  bool b;
  bool sel;
} Mux_Input;

typedef struct
{
  bool out;
} Mux_Output;

typedef struct
{
  Mux_Input input;
  Mux_Output output;
} Mux;

#endif
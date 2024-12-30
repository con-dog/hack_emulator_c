#ifndef MUX_TYPES_H
#define MUX_TYPES_H

#include <stdbool.h>

typedef struct Mux_Input
{
  bool a;
  bool b;
  bool sel;
} Mux_Input;

typedef struct Mux_Output
{
  bool out;
} Mux_Output;

typedef struct Mux
{
  Mux_Input input;
  Mux_Output output;
} Mux;

#endif
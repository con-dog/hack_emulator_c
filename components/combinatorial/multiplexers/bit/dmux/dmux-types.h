#ifndef DMUX_TYPES_H
#define DMUX_TYPES_H

#include <stdbool.h>

typedef struct Dmux_Input
{
  bool in;
  bool sel;
} Dmux_Input;

typedef struct Dmux_Output
{
  bool a;
  bool b;
} Dmux_Output;

typedef struct Dmux
{
  Dmux_Input input;
  Dmux_Output output;
} Dmux;

#endif
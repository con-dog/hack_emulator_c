#ifndef DMUX_4WAY_TYPES_H
#define DMUX_4WAY_TYPES_H

#include <stdbool.h>

typedef struct Dmux_4way_Input
{
  bool in;
  bool sel[2];
} Dmux_4way_Input;

typedef struct Dmux_4way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
} Dmux_4way_Output;

typedef struct Dmux_4way
{
  Dmux_4way_Input input;
  Dmux_4way_Output output;
} Dmux_4way;

#endif
#ifndef DMUX_8WAY_TYPES_H
#define DMUX_8WAY_TYPES_H

#include <stdbool.h>

typedef struct Dmux_8way_Input
{
  bool in;
  bool sel[3];
} Dmux_8way_Input;

typedef struct Dmux_8way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
  bool e;
  bool f;
  bool g;
  bool h;
} Dmux_8way_Output;

typedef struct Dmux_8way
{
  Dmux_8way_Input input;
  Dmux_8way_Output output;
} Dmux_8way;

#endif
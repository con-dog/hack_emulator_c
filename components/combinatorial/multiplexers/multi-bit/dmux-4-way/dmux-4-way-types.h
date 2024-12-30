#ifndef DMUX_4_WAY_TYPES_H
#define DMUX_4_WAY_TYPES_H

#include <stdbool.h>

typedef struct Dmux_4_Way_Input
{
  bool in;
  bool sel[2];
} Dmux_4_Way_Input;

typedef struct Dmux_4_Way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
} Dmux_4_Way_Output;

typedef struct Dmux_4_Way
{
  Dmux_4_Way_Input input;
  Dmux_4_Way_Output output;
} Dmux_4_Way;

#endif
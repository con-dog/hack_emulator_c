#ifndef DMUX_8_WAY_TYPES_H
#define DMUX_8_WAY_TYPES_H

#include <stdbool.h>

typedef struct Dmux_8_Way_Input
{
  bool in;
  bool sel[3];
} Dmux_8_Way_Input;

typedef struct Dmux_8_Way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
  bool e;
  bool f;
  bool g;
  bool h;
} Dmux_8_Way_Output;

typedef struct Dmux_8_Way
{
  Dmux_8_Way_Input input;
  Dmux_8_Way_Output output;
} Dmux_8_Way;

#endif
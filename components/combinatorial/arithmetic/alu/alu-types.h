#ifndef ALU_TYPES_H
#define ALU_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Alu_Input
{
  bool x[WORD_SIZE];
  bool y[WORD_SIZE];
  //
  bool zx;
  bool nx;
  //
  bool zy;
  bool ny;
  //
  bool f;
  bool no;
} Alu_Input;

typedef struct Alu_Output
{
  bool out[WORD_SIZE];
  bool zr;
  bool ng;
} Alu_Output;

typedef struct Alu
{
  Alu_Input input;
  Alu_Output output;
} Alu;

#endif
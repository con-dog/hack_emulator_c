#ifndef FULL_ADDER_TYPES_H
#define FULL_ADDER_TYPES_H

#include <stdbool.h>

typedef struct Full_Adder_Input
{
  bool a;
  bool b;
  bool c;
} Full_Adder_Input;

typedef struct Full_Adder_Output
{
  bool sum;
  bool carry;
} Full_Adder_Output;

typedef struct Full_Adder
{
  Full_Adder_Input input;
  Full_Adder_Output output;
} Full_Adder;

#endif
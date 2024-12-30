#ifndef HALF_ADDER_TYPES_H
#define HALF_ADDER_TYPES_H

#include <stdbool.h>

typedef struct Half_Adder_Input
{
  bool a;
  bool b;
} Half_Adder_Input;

typedef struct Half_Adder_Output
{
  bool sum;
  bool carry;
} Half_Adder_Output;

typedef struct Half_Adder
{
  Half_Adder_Input input;
  Half_Adder_Output output;
} Half_Adder;

#endif
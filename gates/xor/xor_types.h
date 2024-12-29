#ifndef XOR_TYPES_H
#define XOR_TYPES_H

#include <stdbool.h>

typedef struct Xor_Input
{
  bool a;
  bool b;
} Xor_Input;

typedef struct Xor_Output
{
  bool out;
} Xor_Output;

typedef struct Xor
{
  Xor_Input input;
  Xor_Output output;
} Xor;

#endif
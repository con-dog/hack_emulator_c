#ifndef XOR_TYPES_H
#define XOR_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool a;
  bool b;
} Xor_Input;

typedef struct
{
  bool out;
} Xor_Output;

typedef struct
{
  Xor_Input input;
  Xor_Output output;
} Xor;

#endif
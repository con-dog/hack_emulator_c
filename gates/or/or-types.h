#ifndef OR_TYPES_H
#define OR_TYPES_H

#include <stdbool.h>

typedef struct Or_Input
{
  bool a;
  bool b;
} Or_Input;

typedef struct Or_Output
{
  bool out;
} Or_Output;

typedef struct Or
{
  Or_Input input;
  Or_Output output;
} Or;

#endif
#ifndef ADD16_TYPES_H
#define ADD16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct Add16_Input
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
} Add16_Input;

typedef struct Add16_Output
{
  bool out[WORD_SIZE];
} Add16_Output;

typedef struct Add16
{
  Add16_Input input;
  Add16_Output output;
} Add16;

#endif
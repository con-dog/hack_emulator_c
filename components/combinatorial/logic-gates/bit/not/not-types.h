#ifndef NOT_TYPES_H
#define NOT_TYPES_H

#include <stdbool.h>

typedef struct Not_Input
{
  bool in;
} Not_Input;

typedef struct Not_Output
{
  bool out;
} Not_Output;

typedef struct Not
{
  Not_Input input;
  Not_Output output;
} Not;

#endif
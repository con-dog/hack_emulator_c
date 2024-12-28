#ifndef NOT_TYPES_H
#define NOT_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool in;
} Not_Input;

typedef struct
{
  bool out;
} Not_Output;

typedef struct
{
  Not_Input input;
  Not_Output output;
} Not;

#endif
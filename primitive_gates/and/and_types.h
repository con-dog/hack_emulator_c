#ifndef AND_TYPES_H
#define AND_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool a;
  bool b;
} And_Input;

typedef struct
{
  bool out;
} And_Output;

typedef struct
{
  And_Input input;
  And_Output output;
} And;

#endif
#ifndef AND_TYPES_H
#define AND_TYPES_H

#include <stdbool.h>

typedef struct And_Input
{
  bool a;
  bool b;
} And_Input;

typedef struct And_Output
{
  bool out;
} And_Output;

typedef struct And
{
  And_Input input;
  And_Output output;
} And;

#endif
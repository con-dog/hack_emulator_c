#ifndef AND16_TYPES_H
#define AND16_TYPES_H

#include <stdbool.h>
#include "types.h"

typedef struct
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
} And16_Input;

typedef struct
{
  bool out[WORD_SIZE];
} And16_Output;

typedef struct
{
  And16_Input input;
  And16_Output output;
} And16;

#endif
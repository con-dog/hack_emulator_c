#ifndef NAND_TYPES_H
#define NAND_TYPES_H

#include <stdbool.h>

typedef struct
{
  bool a;
  bool b;
} Nand_Input;

typedef struct
{
  bool out;
} Nand_Output;

typedef struct
{
  Nand_Input input;
  Nand_Output output;
} Nand;

#endif
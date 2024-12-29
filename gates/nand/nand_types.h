#ifndef NAND_TYPES_H
#define NAND_TYPES_H

#include <stdbool.h>

typedef struct Nand_Input
{
  bool a;
  bool b;
} Nand_Input;

typedef struct Nand_Output
{
  bool out;
} Nand_Output;

typedef struct Nand
{
  Nand_Input input;
  Nand_Output output;
} Nand;

#endif
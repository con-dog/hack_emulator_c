#ifndef TEST_NAND_H
#define TEST_NAND_H

#include <stdbool.h>
#include "test-utils.h"

typedef struct Nand_TT
{
  bool a;
  bool b;
  bool c;
} Nand_TT;

void test_nand(Test_Counter *counter);

#endif
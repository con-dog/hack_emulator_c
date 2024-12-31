// Truth Table
/*
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */
#include <stdio.h>

#include "test-nand.h"
#include "nand.h"
#include "test-utils.h"

void test_nand(Test_Counter *counter)
{
  // Truth table for NAND: expected outputs
  const int expected[4] = {1, 1, 1, 0}; // outputs for (0,0), (0,1), (1,0), (1,1)
  for (int i = 0; i < 4; i++)
  {
    Nand nand = {
        .input.a = (i >> 1) & 1, // Gets first bit  (0011)
        .input.b = i & 1,        // Gets second bit (0101)
    };
    nand_gate(&nand);
    test_assert(nand.output.out == expected[i], counter,
                "NAND(%d,%d) should be %d",
                nand.input.a,
                nand.input.b,
                expected[i]);
  }
}
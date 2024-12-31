
#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/add16/add16.h"
#include "components/combinatorial/arithmetic/inc16/inc16.h"
#include "components/combinatorial/arithmetic/full-adder/full-adder.h"
#include "components/combinatorial/arithmetic/alu/alu.h"

// For testing purposes
#include "components/combinatorial/logic-gates/bit/nand/nand.h"

void nand_test(void)
{
  // Define Gate
  Nand nand_instance;

  //---------------
  // Test 1
  //---------------

  // Set input values
  nand_instance.input.a = 0;
  nand_instance.input.b = 0;

  // Evaluate
  nand_gate(&nand_instance);

  // Check output
  if (nand_instance.output.out == 1)
  {
    printf("Test 1 PASSED\n");
  }
  else
  {
    printf("Test 1 FAILED\n");
  }

  //---------------
  // Test 2
  //---------------

  // Set input values
  nand_instance.input.a = 0;
  nand_instance.input.b = 1;

  // Evaluate
  nand_gate(&nand_instance);

  // Check output
  if (nand_instance.output.out == 1)
  {
    printf("Test 2 PASSED\n");
  }
  else
  {
    printf("Test 2 FAILED\n");
  }

  //---------------
  // Test 3
  //---------------

  // Set input values
  nand_instance.input.a = 1;
  nand_instance.input.b = 0;

  // Evaluate
  nand_gate(&nand_instance);

  // Check output
  if (nand_instance.output.out == 1)
  {
    printf("Test 3 PASSED\n");
  }
  else
  {
    printf("Test 3 FAILED\n");
  }

  //---------------
  // Test 4
  //---------------

  // Set input values
  nand_instance.input.a = 1;
  nand_instance.input.b = 1;

  // Evaluate
  nand_gate(&nand_instance);

  // Check output
  if (nand_instance.output.out == 0)
  {
    printf("Test 4 PASSED\n");
  }
  else
  {
    printf("Test 4 FAILED\n");
  }
}

int main(void)
{
  nand_test();

  // Alu alu = {
  //     .input.x = {0},
  //     .input.y = {[0 ... WORD_SIZE - 1] = 1},
  //     //
  //     .input.zx = 1,
  //     .input.nx = 1,
  //     //
  //     .input.zy = 1,
  //     .input.ny = 0,
  //     //
  //     .input.f = 1,
  //     .input.no = 0,
  // };
  // alu_chip(&alu);

  // for (int i = WORD_SIZE - 1; i >= 0; i--)
  // {
  //   printf("%d", alu.output.out[i]);
  // }
  // printf("\n");
  // printf("%d\n", alu.output.zr);
  // printf("%d\n", alu.output.ng);
}
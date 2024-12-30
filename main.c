#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/add16/add16.h"
#include "components/combinatorial/arithmetic/inc16/inc16.h"
#include "components/combinatorial/arithmetic/full-adder/full-adder.h"
#include "components/combinatorial/arithmetic/alu/alu.h"

int main(void)
{
  Alu alu = {
      .input.x = {0},
      .input.y = {[0 ... WORD_SIZE - 1] = 1},
      //
      .input.zx = 1,
      .input.nx = 1,
      //
      .input.zy = 1,
      .input.ny = 0,
      //
      .input.f = 1,
      .input.no = 0,
  };
  alu_chip(&alu);

  for (int i = WORD_SIZE - 1; i >= 0; i--)
  {
    printf("%d", alu.output.out[i]);
  }
  printf("\n");
  printf("%d\n", alu.output.zr);
  printf("%d\n", alu.output.ng);
}
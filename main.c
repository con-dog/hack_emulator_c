#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/add16/add16.h"
#include "components/combinatorial/arithmetic/inc16/inc16.h"
#include "components/combinatorial/arithmetic/full-adder/full-adder.h"

int main(void)
{

  // Inc16 inc16_unit;

  // for (int i = 0; i < WORD_SIZE; i++)
  // {
  //   inc16_unit.input.in[i] = 0;
  // }
  // inc16_chip(&inc16_unit);

  // for (int i = WORD_SIZE - 1; i >= 0; i--)
  // {
  //   printf("%d", inc16_unit.output.out[i]);
  // }
  Add16 add16_unit = {
      .input.a = {[0 ... WORD_SIZE - 1] = 1},
      .input.b = {[0 ... WORD_SIZE - 1] = 1},
  };
  add16_chip(&add16_unit);

  for (int i = WORD_SIZE - 1; i >= 0; i--)
  {
    printf("%d", add16_unit.output.out[i]);
  }

  printf("\n");
}
#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/full-adder/full-adder.h"

int main(void)
{
  Full_Adder full_adder_unit;

  full_adder_unit.input.a = 1;
  full_adder_unit.input.b = 1;
  full_adder_unit.input.c = 1;
  full_adder_chip(&full_adder_unit);

  printf("%d %d\n", full_adder_unit.output.sum, full_adder_unit.output.carry);
  printf("\n");
}
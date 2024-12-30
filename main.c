#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/half-adder/half-adder.h"

int main(void)
{
  Half_Adder half_adder_unit;

  half_adder_unit.input.a = 0;
  half_adder_unit.input.b = 0;
  half_adder_chip(&half_adder_unit);

  printf("%d %d\n", half_adder_unit.output.sum, half_adder_unit.output.carry);
  printf("\n");
}
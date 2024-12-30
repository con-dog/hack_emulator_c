#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/arithmetic/add16/add16.h"

int main(void)
{
  Add16 add16_unit;

  for (int i = 0; i < WORD_SIZE; i++)
  {
    add16_unit.input.a[i] = 1;
    add16_unit.input.b[i] = 1;
  }
  add16_chip(&add16_unit);

  for (int i = WORD_SIZE - 1; i >= 0; i--)
  {
    printf("%d", add16_unit.output.out[i]);
  }
  printf("\n");
}
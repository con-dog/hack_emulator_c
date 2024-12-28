#include <stdio.h>
#include "primitive_gates/not/not.h"
#include "primitive_gates/nand/nand.h"

int main(void)
{
  Nand nand = {
      .input.a = false,
      .input.b = false,
  };

  nand_gate(&nand);
  Not not = {
      .input.in = nand.output.out};
  not_gate(&not );
  printf("%d\n%d\n", nand.output.out, not .output.out);
}
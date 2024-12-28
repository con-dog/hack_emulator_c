#include <stdio.h>
#include "primitive_gates/not/not.h"
#include "primitive_gates/nand/nand.h"
#include "primitive_gates/and/and.h"
#include "primitive_gates/or/or.h"

int main(void)
{

  And and = {
      .input.a = false,
      .input.b = false,
  };

  Or or = {
            .input.a = false,
            .input.b = false,
        };

  and_gate(&and);
  or_gate(& or);
  // nand_gate(&nand);
  // Not not = {
  //     .input.in = nand.output.out};
  // not_gate(&not );
  printf("%d\n%d\n", and.output.out, or.output.out);
}
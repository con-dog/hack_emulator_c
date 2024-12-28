#include "or.h"
#include "not.h"
#include "nand.h"

void or_gate(Or * or)
{
  Not not = {
      .input.in = or->input.a,
  };
  not_gate(&not );

  Nand nandA = {
      .input.a = not .output.out,
      .input.b = or->input.b,
  };
  nand_gate(&nandA);

  Nand nandB = {
      .input.a = not .output.out,
      .input.b = nandA.output.out,
  };
  nand_gate(&nandB);

  or->output.out = nandB.output.out;
}

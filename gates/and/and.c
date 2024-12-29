#include "and.h"
#include "nand.h"
#include "not.h"

void and_gate(And *and)
{
  Nand nand = {
      .input.a = and->input.a,
      .input.b = and->input.b,
  };
  nand_gate(&nand);

  Not not = {
      .input.in = nand.output.out,
  };
  not_gate(&not );

  and->output.out = not .output.out;
}

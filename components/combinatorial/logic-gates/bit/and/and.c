#include "and.h"
#include "nand.h"
#include "not.h"

void and_gate(And *and_unit)
{
  Nand nand_unit = {
      .input.a = and_unit->input.a,
      .input.b = and_unit->input.b,
  };
  nand_gate(&nand_unit);

  Not not_unit = {
      .input.in = nand_unit.output.out,
  };
  not_gate(&not_unit);

  and_unit->output.out = not_unit.output.out;
}

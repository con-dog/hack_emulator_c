#include "or.h"
#include "not.h"
#include "nand.h"

void or_gate(Or *or_unit)
{
  Not not_unit = {
      .input.in = or_unit->input.a,
  };
  not_gate(&not_unit);

  Nand nand_unit_1 = {
      .input.a = not_unit.output.out,
      .input.b = or_unit->input.b,
  };
  nand_gate(&nand_unit_1);

  Nand nand_unit_2 = {
      .input.a = not_unit.output.out,
      .input.b = nand_unit_1.output.out,
  };
  nand_gate(&nand_unit_2);

  or_unit->output.out = nand_unit_2.output.out;
}

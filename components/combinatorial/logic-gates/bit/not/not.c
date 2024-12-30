#include "nand.h"
#include "not.h"

void not_gate(Not *not_unit)
{
  Nand nand_unit = {
      .input.a = not_unit->input.in,
      .input.b = not_unit->input.in,
  };
  nand_gate(&nand_unit);
  not_unit->output.out = nand_unit.output.out;
}

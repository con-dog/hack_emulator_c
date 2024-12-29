#include "nand.h"
#include "not.h"

void not_gate(Not * not )
{
  Nand nand = {
      .input.a = not ->input.in,
      .input.b = not ->input.in,
  };
  nand_gate(&nand);
  not ->output.out = nand.output.out;
}

#include "nand.h"

void nand_gate(Nand *nand)
{
  nand->output.out = !(nand->input.a & nand->input.b);
}

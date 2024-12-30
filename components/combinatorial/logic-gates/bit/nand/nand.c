#include "nand.h"

/*
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */
void nand_gate(Nand *nand_unit)
{
  nand_unit->output.out = !(nand_unit->input.a & nand_unit->input.b);
}

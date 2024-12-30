#include "nand.h"

/*
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */
void nand_gate(Nand *nand)
{
  nand->output.out = !(nand->input.a & nand->input.b);
}

#include "not16.h"
#include "not.h"
#include "types.h"

void not16_gate(Not16 *not16_unit)
{
  Not not_units[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    not_units[i].input.in = not16_unit->input.in[i];
    not_gate(&not_units[i]);
    not16_unit->output.out[i] = not_units[i].output.out;
  }
}
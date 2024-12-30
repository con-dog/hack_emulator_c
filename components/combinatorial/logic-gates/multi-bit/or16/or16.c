#include "or16.h"
#include "or.h"
#include "types.h"

void or16_gate(Or16 *or16_unit)
{
  Or or_units[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    or_units[i].input.a = or16_unit->input.a[i];
    or_units[i].input.b = or16_unit->input.b[i];
    or_gate(&or_units[i]);
    or16_unit->output.out[i] = or_units[i].output.out;
  }
}

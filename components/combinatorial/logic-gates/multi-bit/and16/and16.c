#include "and16.h"
#include "and.h"
#include "types.h"

void and16_gate(And16 *and16_unit)
{
  And and_gate_units[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    and_gate_units[i].input.a = and16_unit->input.a[i];
    and_gate_units[i].input.b = and16_unit->input.b[i];
    and_gate(&and_gate_units[i]);
    and16_unit->output.out[i] = and_gate_units[i].output.out;
  }
}

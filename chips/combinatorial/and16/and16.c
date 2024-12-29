#include "and16.h"
#include "and.h"
#include "types.h"

void and16_chip(And16 *and16)
{
  And and_gates[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    and_gates[i].input.a = and16->input.a[i];
    and_gates[i].input.b = and16->input.b[i];
    and_gate(&and_gates[i]);
    and16->output.out[i] = and_gates[i].output.out;
  }
}

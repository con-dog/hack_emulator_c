#include "or16.h"
#include "or.h"
#include "types.h"

void or16_chip(Or16 *or16)
{
  Or or_gates[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    or_gates[i].input.a = or16->input.a[i];
    or_gates[i].input.b = or16->input.b[i];
    or_gate(&or_gates[i]);
    or16->output.out[i] = or_gates[i].output.out;
  }
}

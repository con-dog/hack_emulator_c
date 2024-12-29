#include "not16.h"
#include "not.h"
#include "types.h"

void not16_chip(Not16 *not16)
{
  Not not_gates[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    not_gates[i].input.in = not16->input.in[i];
    not_gate(&not_gates[i]);
    not16->output.out[i] = not_gates[i].output.out;
  }
}
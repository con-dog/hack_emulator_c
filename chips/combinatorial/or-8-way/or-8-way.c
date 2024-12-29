#include "or-8-way.h"
#include "or.h"
#include "types.h"

void or_8_way_chip(Or_8_Way *or_8_way)
{
  Or or_gates_phase_a[BYTE_SIZE / 2];
  for (int i = 0; i < BYTE_SIZE / 2; i++)
  {
    or_gates_phase_a[i].input.a = or_8_way->input.in[i];
    or_gates_phase_a[i].input.b = or_8_way->input.in[i + BYTE_SIZE / 2];
    or_gate(&or_gates_phase_a[i]);
  }

  Or or_gates_phase_b[BYTE_SIZE / 4];
  for (int i = 0; i < BYTE_SIZE / 4; i++)
  {
    or_gates_phase_b[i].input.a = or_gates_phase_a[i].output.out;
    or_gates_phase_b[i].input.b = or_gates_phase_a[i + BYTE_SIZE / 4].output.out;
    or_gate(&or_gates_phase_b[i]);
  }

  Or or_phase_c = {
      .input.a = or_gates_phase_b[0].output.out,
      .input.b = or_gates_phase_b[1].output.out,
  };

  or_8_way->output.out = or_phase_c.output.out;
}

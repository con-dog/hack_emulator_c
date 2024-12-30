#include "or-8way.h"
#include "or.h"
#include "types.h"

void or_8way_gate(Or_8way *or_8way)
{
  Or or_units_block_a[BYTE_SIZE / 2];
  for (int i = 0; i < BYTE_SIZE / 2; i++)
  {
    or_units_block_a[i].input.a = or_8way->input.in[i];
    or_units_block_a[i].input.b = or_8way->input.in[i + BYTE_SIZE / 2];
    or_gate(&or_units_block_a[i]);
  }

  Or or_units_block_b[BYTE_SIZE / 4];
  for (int i = 0; i < BYTE_SIZE / 4; i++)
  {
    or_units_block_b[i].input.a = or_units_block_a[i].output.out;
    or_units_block_b[i].input.b = or_units_block_a[i + BYTE_SIZE / 4].output.out;
    or_gate(&or_units_block_b[i]);
  }

  Or or_unit = {
      .input.a = or_units_block_b[0].output.out,
      .input.b = or_units_block_b[1].output.out,
  };
  or_gate(&or_unit);

  or_8way->output.out = or_unit.output.out;
}

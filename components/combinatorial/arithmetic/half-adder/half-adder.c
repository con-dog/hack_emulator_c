#include "half-adder.h"
#include "and.h"
#include "xor.h"

void half_adder_chip(Half_Adder *half_adder_unit)
{
  Xor xor_unit = {
      .input.a = half_adder_unit->input.a,
      .input.b = half_adder_unit->input.b,
  };

  And and_unit = {
      .input.a = half_adder_unit->input.a,
      .input.b = half_adder_unit->input.b,
  };

  xor_gate(&xor_unit);
  and_gate(&and_unit);
  half_adder_unit->output.sum = xor_unit.output.out;
  half_adder_unit->output.carry = and_unit.output.out;
}

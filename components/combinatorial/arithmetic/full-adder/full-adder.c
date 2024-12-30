#include "full-adder.h"
#include "half-adder.h"
#include "or.h"

void full_adder_chip(Full_Adder *full_adder_unit)
{
  Half_Adder half_adder_unit_1 = {
      .input.a = full_adder_unit->input.b,
      .input.b = full_adder_unit->input.c};
  half_adder_chip(&half_adder_unit_1);

  Half_Adder half_adder_unit_2 = {
      .input.a = full_adder_unit->input.a,
      .input.b = half_adder_unit_1.output.sum,
  };
  half_adder_chip(&half_adder_unit_2);

  Or or_unit = {
      .input.a = half_adder_unit_1.output.carry,
      .input.b = half_adder_unit_2.output.carry,
  };
  or_gate(&or_unit);

  full_adder_unit->output.sum = half_adder_unit_2.output.sum;
  full_adder_unit->output.carry = or_unit.output.out;
}

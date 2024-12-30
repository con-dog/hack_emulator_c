#include "xor.h"
#include "not.h"
#include "and.h"
#include "or.h"

void xor_gate(Xor *xor_unit)
{
  Not not_unit_1 = {
      .input.in = xor_unit->input.a};
  not_gate(&not_unit_1);

  Not not_unit_2 = {
      .input.in = xor_unit->input.b};
  not_gate(&not_unit_2);

  And and_unit_1 = {
      .input.a = not_unit_1.output.out,
      .input.b = xor_unit->input.b,
  };
  and_gate(&and_unit_1);

  And and_unit_2 = {
      .input.a = xor_unit->input.a,
      .input.b = not_unit_2.output.out};
  and_gate(&and_unit_2);

  Or or_unit = {
      .input.a = and_unit_1.output.out,
      .input.b = and_unit_2.output.out,
  };
  or_gate(&or_unit);

  xor_unit->output.out = or_unit.output.out;
}

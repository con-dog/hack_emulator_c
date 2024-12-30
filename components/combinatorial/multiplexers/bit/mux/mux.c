#include "mux.h"
#include "and.h"
#include "not.h"
#include "or.h"

void mux_chip(Mux *mux_unit)
{
  Not not_unit = {
      .input.in = mux_unit->input.sel};
  not_gate(&not_unit);

  And and_unit_1 = {
      .input.a = mux_unit->input.a,
      .input.b = not_unit.output.out,
  };
  and_gate(&and_unit_1);

  And and_unit_2 = {
      .input.a = mux_unit->input.sel,
      .input.b = mux_unit->input.b,
  };
  and_gate(&and_unit_2);

  Or or_unit = {
      .input.a = and_unit_1.output.out,
      .input.b = and_unit_2.output.out,
  };
  or_gate(&or_unit);

  mux_unit->output.out = or_unit.output.out;
}

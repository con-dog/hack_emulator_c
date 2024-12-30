#include "dmux.h"
#include "and.h"
#include "not.h"

void dmux_chip(Dmux *dmux_unit)
{
  Not not_unit = {
      .input.in = dmux_unit->input.sel,
  };
  not_gate(&not_unit);

  And and_unit_1 = {
      .input.a = dmux_unit->input.in,
      .input.b = not_unit.output.out,
  };
  And and_unit_2 = {
      .input.a = dmux_unit->input.sel,
      .input.b = dmux_unit->input.in,
  };

  and_gate(&and_unit_1);
  and_gate(&and_unit_2);
  dmux_unit->output.a = and_unit_1.output.out;
  dmux_unit->output.b = and_unit_2.output.out;
}

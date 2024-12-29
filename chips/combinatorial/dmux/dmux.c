#include "dmux.h"
#include "./gates/and/and.h"
#include "./gates/not/not.h"

void dmux_chip(Dmux *dmux)
{
  Not not = {
      .input.in = dmux->input.sel,
  };
  not_gate(&not );

  And and_a = {
      .input.a = dmux->input.in,
      .input.b = not .output.out,
  };
  And and_b = {
      .input.a = dmux->input.sel,
      .input.b = dmux->input.in,
  };

  and_gate(&and_a);
  and_gate(&and_b);

  dmux->output.a = and_a.output.out;
  dmux->output.b = and_b.output.out;
}

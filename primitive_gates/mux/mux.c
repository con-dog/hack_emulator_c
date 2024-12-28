#include "mux.h"
#include "and.h"
#include "not.h"
#include "or.h"

void mux_gate(Mux *mux)
{
  Not not = {
      .input.in = mux->input.sel};
  not_gate(&not );

  And and_a = {
      .input.a = mux->input.a,
      .input.b = not .output.out,
  };
  and_gate(&and_a);

  And and_b = {
      .input.a = mux->input.sel,
      .input.b = mux->input.b,
  };
  and_gate(&and_b);

  Or or = {
            .input.a = and_a.output.out,
            .input.b = and_b.output.out,
        };
  or_gate(& or);

  mux->output.out = or.output.out;
}

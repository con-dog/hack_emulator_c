#include "xor.h"
#include "not.h"
#include "and.h"
#include "or.h"

void xor_gate(Xor *xor_gate_instance)
{
  Not not_a = {
      .input.in = xor_gate_instance->input.a};
  not_gate(&not_a);

  Not not_b = {
      .input.in = xor_gate_instance->input.b};
  not_gate(&not_b);

  And and_a = {
      .input.a = not_a.output.out,
      .input.b = xor_gate_instance->input.b,
  };
  and_gate(&and_a);

  And and_b = {
      .input.a = xor_gate_instance->input.a,
      .input.b = not_b.output.out};
  and_gate(&and_b);

  Or or = {
            .input.a = and_a.output.out,
            .input.b = and_b.output.out,
        };
  or_gate(& or);

  xor_gate_instance->output.out = or.output.out;
}

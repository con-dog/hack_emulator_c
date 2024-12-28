#include <stdio.h>
#include "primitive_gates/not/not.h"
#include "primitive_gates/nand/nand.h"
#include "primitive_gates/and/and.h"
#include "primitive_gates/or/or.h"
#include "primitive_gates/xor/xor.h"
#include "primitive_gates/mux/mux.h"

int main(void)
{
  And and = {
      .input.a = false,
      .input.b = false,
  };

  Or or = {
            .input.a = false,
            .input.b = false,
        };

  Xor xor = {
              .input.a = false,
              .input.b = false,
          };

  Mux mux = {
      .input.a = false,
      .input.b = true,
      .input.sel = true,
  };

  and_gate(&and);
  or_gate(& or);
  xor_gate(&xor);
  mux_gate(&mux);

  printf("%d\n%d\n%d\n%d\n", and.output.out, or.output.out, xor.output.out, mux.output.out);
}
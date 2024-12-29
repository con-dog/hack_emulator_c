#include <stdio.h>
#include "gates/not/not.h"
#include "gates/nand/nand.h"
#include "gates/and/and.h"
#include "gates/or/or.h"
#include "gates/xor/xor.h"
#include "chips/combinatorial/mux/mux.h"
#include "chips/combinatorial/dmux/dmux.h"
#include "chips/combinatorial/not16/not16.h"

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

  Dmux dmux = {
      .input.in = true,
      .input.sel = true,
  };

  Not16 not16;

  for (int i = 0; i < 16; i++)
  {
    not16.input.in[i] = 1;
  }

  and_gate(&and);
  or_gate(& or);
  xor_gate(&xor);
  //
  mux_chip(&mux);
  dmux_chip(&dmux);
  //
  not16_chip(&not16);

  for (int i = 0; i < 16; i++)
  {
    printf("%d", not16.output.out[i]);
  }
  printf("\n");
}
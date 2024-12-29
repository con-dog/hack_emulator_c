#include <stdio.h>
#include "gates/not/not.h"
#include "gates/nand/nand.h"
#include "gates/and/and.h"
#include "gates/or/or.h"
#include "gates/xor/xor.h"
#include "chips/combinatorial/mux/mux.h"
#include "chips/combinatorial/dmux/dmux.h"
#include "chips/combinatorial/not16/not16.h"
#include "chips/combinatorial/and16/and16.h"
#include "chips/combinatorial/or16/or16.h"
#include "chips/combinatorial/or-8-way/or-8-way.h"
#include "types/types.h"

int main(void)
{

  Or_8_Way or_8_way;

  // for (int i = 0; i < WORD_SIZE; i++)
  // {
  //   not16.input.in[i] = 1;
  // }

  // for (int i = 0; i < WORD_SIZE; i++)
  // {
  //   and16.input.a[i] = 1;
  //   and16.input.b[i] = 1;
  //   or16.input.a[i] = 0;
  //   or16.input.b[i] = 0;
  // }

  for (int i = 0; i < BYTE_SIZE; i++)
  {
    or_8_way.input.in[i] = 0;
  }

  or_8_way.input.in[0] = 1;

  // and_gate(&and);
  // or_gate(& or);
  // xor_gate(&xor);
  // //
  // mux_chip(&mux);
  // dmux_chip(&dmux);
  // //
  // not16_chip(&not16);
  // and16_chip(&and16);
  // or16_chip(&or16);
  or_8_way_chip(&or_8_way);

  printf("%d", or_8_way.output.out);
  printf("\n");
}
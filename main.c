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
#include "chips/combinatorial/mux16-4-way/mux16-4-way.h"
#include "types/types.h"

int main(void)
{
  Mux16_4_Way mux16_4_way;
  for (int i = 0; i < WORD_SIZE / 2; i++)
  {
    mux16_4_way.input.a[i] = 0;
    mux16_4_way.input.b[i] = 0;
    mux16_4_way.input.c[i] = 1;
    mux16_4_way.input.d[i] = 1;
  }

  for (int i = WORD_SIZE / 2; i < WORD_SIZE; i++)
  {
    mux16_4_way.input.a[i] = 0;
    mux16_4_way.input.b[i] = 1;
    mux16_4_way.input.c[i] = 0;
    mux16_4_way.input.d[i] = 1;
  }

  mux16_4_way.input.sel[0] = 1;
  mux16_4_way.input.sel[1] = 0;

  mux16_4_way_chip(&mux16_4_way);

  for (int i = 0; i < WORD_SIZE; i++)
  {
    printf("%d", mux16_4_way.output.out[i]);
  }
  printf("\n");
}
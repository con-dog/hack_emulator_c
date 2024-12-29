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
#include "chips/combinatorial/mux16-8-way/mux16-8-way.h"
#include "types/types.h"

int main(void)
{
  Mux16_8_Way mux16_8_way;
  for (int i = 0; i < 4; i++)
  {
    mux16_8_way.input.a[i] = 0;
    mux16_8_way.input.b[i] = 0;
    mux16_8_way.input.c[i] = 0;
    mux16_8_way.input.d[i] = 0;
    mux16_8_way.input.e[i] = 1;
    mux16_8_way.input.f[i] = 1;
    mux16_8_way.input.g[i] = 1;
    mux16_8_way.input.h[i] = 1;
  }

  for (int i = 4; i < 10; i++)
  {
    mux16_8_way.input.a[i] = 0;
    mux16_8_way.input.b[i] = 1;
    mux16_8_way.input.c[i] = 0;
    mux16_8_way.input.d[i] = 1;
    mux16_8_way.input.e[i] = 0;
    mux16_8_way.input.f[i] = 1;
    mux16_8_way.input.g[i] = 0;
    mux16_8_way.input.h[i] = 1;
  }

  for (int i = 10; i < WORD_SIZE; i++)
  {
    mux16_8_way.input.a[i] = 1;
    mux16_8_way.input.b[i] = 1;
    mux16_8_way.input.c[i] = 1;
    mux16_8_way.input.d[i] = 1;
    mux16_8_way.input.e[i] = 0;
    mux16_8_way.input.f[i] = 0;
    mux16_8_way.input.g[i] = 0;
    mux16_8_way.input.h[i] = 0;
  }

  mux16_8_way.input.sel[0] = 0;
  mux16_8_way.input.sel[1] = 0;
  mux16_8_way.input.sel[2] = 1;

  mux16_8_way_chip(&mux16_8_way);

  for (int i = 0; i < WORD_SIZE; i++)
  {
    printf("%d", mux16_8_way.output.out[i]);
  }
  printf("\n");
}
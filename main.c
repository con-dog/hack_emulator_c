#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/multiplexers/multi-bit/dmux-8way/dmux-8way.h"

int main(void)
{
  Dmux_8way dmux_8way = {
      .input.in = 1,
      .input.sel = {1, 1, 1},
  };

  dmux_8way_chip(&dmux_8way);

  printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", dmux_8way.output.a, dmux_8way.output.b, dmux_8way.output.c, dmux_8way.output.d, dmux_8way.output.e, dmux_8way.output.f, dmux_8way.output.g, dmux_8way.output.h);
  printf("\n");
}
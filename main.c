#include <stdio.h>
#include "types/types.h"
#include "components/combinatorial/multiplexers/multi-bit/dmux-8-way/dmux-8-way.h"

int main(void)
{
  Dmux_8_Way dmux_8_way = {
      .input.in = 1,
      .input.sel = {1, 1, 1},
  };

  dmux_8_way_chip(&dmux_8_way);

  printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", dmux_8_way.output.a, dmux_8_way.output.b, dmux_8_way.output.c, dmux_8_way.output.d, dmux_8_way.output.e, dmux_8_way.output.f, dmux_8_way.output.g, dmux_8_way.output.h);
  printf("\n");
}
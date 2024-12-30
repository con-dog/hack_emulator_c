#include <string.h>
#include "dmux-8-way.h"
#include "dmux-4-way.h"
#include "dmux.h"

/*
 * [a, b, c, d, e, f, g, h] = [in, 0,  0,  0,  0,  0,  0,  0] if sel = 000
 *                            [0, in,  0,  0,  0,  0,  0,  0] if sel = 001
 *                            [0,  0, in,  0,  0,  0,  0,  0] if sel = 010
 *                            [0,  0,  0, in,  0,  0,  0,  0] if sel = 011
 *                            [0,  0,  0,  0, in,  0,  0,  0] if sel = 100
 *                            [0,  0,  0,  0,  0, in,  0,  0] if sel = 101
 *                            [0,  0,  0,  0,  0,  0, in,  0] if sel = 110
 *                            [0,  0,  0,  0,  0,  0,  0, in] if sel = 111
 */
void dmux_8_way_chip(Dmux_8_Way *dmux_8_way)
{
  Dmux dmux;
  Dmux_4_Way dmux_4_way_a, dmux_4_way_b;

  // dmux
  dmux.input.in = dmux_8_way->input.in;
  dmux.input.sel = dmux_8_way->input.sel[2];
  dmux_chip(&dmux);

  // dmux 4way a
  dmux_4_way_a.input.in = dmux.output.a;
  memcpy(dmux_4_way_a.input.sel, dmux_8_way->input.sel, sizeof(dmux_4_way_a.input.sel));
  dmux_4_way_chip(&dmux_4_way_a);

  // dmux 4way b
  dmux_4_way_b.input.in = dmux.output.b;
  memcpy(dmux_4_way_b.input.sel, dmux_8_way->input.sel, sizeof(dmux_4_way_b.input.sel));
  dmux_4_way_chip(&dmux_4_way_b);

  // output
  dmux_8_way->output.a = dmux_4_way_a.output.a;
  dmux_8_way->output.b = dmux_4_way_a.output.b;
  dmux_8_way->output.c = dmux_4_way_a.output.c;
  dmux_8_way->output.d = dmux_4_way_a.output.d;
  dmux_8_way->output.e = dmux_4_way_b.output.a;
  dmux_8_way->output.f = dmux_4_way_b.output.b;
  dmux_8_way->output.g = dmux_4_way_b.output.c;
  dmux_8_way->output.h = dmux_4_way_b.output.d;
}

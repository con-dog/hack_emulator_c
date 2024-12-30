#include "dmux-4-way.h"
#include "dmux.h"

/*
 * [a, b, c, d] = [in, 0, 0, 0] if sel = 00
 *                [0, in, 0, 0] if sel = 01
 *                [0, 0, in, 0] if sel = 10
 *                [0, 0, 0, in] if sel = 11
 */
void dmux_4_way_chip(Dmux_4_Way *dmux_4_way)
{
  Dmux dmux_a, dmux_b, dmux_c;

  // dmux a
  dmux_a.input.in = dmux_4_way->input.in;
  dmux_a.input.sel = dmux_4_way->input.sel[1];
  dmux_chip(&dmux_a);

  // dmux b
  dmux_b.input.in = dmux_a.output.a;
  dmux_b.input.sel = dmux_4_way->input.sel[0];
  dmux_chip(&dmux_b);

  // dmux c
  dmux_c.input.in = dmux_a.output.b;
  dmux_c.input.sel = dmux_4_way->input.sel[0];
  dmux_chip(&dmux_c);

  // output
  dmux_4_way->output.a = dmux_b.output.a;
  dmux_4_way->output.b = dmux_b.output.b;
  dmux_4_way->output.c = dmux_c.output.a;
  dmux_4_way->output.d = dmux_c.output.b;
}

#include <string.h>
#include "dmux-8way.h"
#include "dmux-4way.h"
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
void dmux_8way_chip(Dmux_8way *dmux_8way_unit)
{
  Dmux dmux_unit;
  Dmux_4way dmux_4way_unit_1, dmux_4way_unit_2;

  // dmux
  dmux_unit.input.in = dmux_8way_unit->input.in;
  dmux_unit.input.sel = dmux_8way_unit->input.sel[2];
  dmux_chip(&dmux_unit);

  dmux_4way_unit_1.input.in = dmux_unit.output.a;
  memcpy(dmux_4way_unit_1.input.sel, dmux_8way_unit->input.sel, sizeof(dmux_4way_unit_1.input.sel));
  dmux_4way_chip(&dmux_4way_unit_1);

  dmux_4way_unit_2.input.in = dmux_unit.output.b;
  memcpy(dmux_4way_unit_2.input.sel, dmux_8way_unit->input.sel, sizeof(dmux_4way_unit_2.input.sel));
  dmux_4way_chip(&dmux_4way_unit_2);

  dmux_8way_unit->output.a = dmux_4way_unit_1.output.a;
  dmux_8way_unit->output.b = dmux_4way_unit_1.output.b;
  dmux_8way_unit->output.c = dmux_4way_unit_1.output.c;
  dmux_8way_unit->output.d = dmux_4way_unit_1.output.d;
  dmux_8way_unit->output.e = dmux_4way_unit_2.output.a;
  dmux_8way_unit->output.f = dmux_4way_unit_2.output.b;
  dmux_8way_unit->output.g = dmux_4way_unit_2.output.c;
  dmux_8way_unit->output.h = dmux_4way_unit_2.output.d;
}

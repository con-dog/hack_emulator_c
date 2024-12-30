#include "dmux-4way.h"
#include "dmux.h"

/*
 * [a, b, c, d] = [in, 0, 0, 0] if sel = 00
 *                [0, in, 0, 0] if sel = 01
 *                [0, 0, in, 0] if sel = 10
 *                [0, 0, 0, in] if sel = 11
 */
void dmux_4way_chip(Dmux_4way *dmux_4way_unit)
{
  Dmux dmux_unit_1, dmux_unit_2, dmux_unit_3;

  dmux_unit_1.input.in = dmux_4way_unit->input.in;
  dmux_unit_1.input.sel = dmux_4way_unit->input.sel[1];
  dmux_chip(&dmux_unit_1);

  dmux_unit_2.input.in = dmux_unit_1.output.a;
  dmux_unit_2.input.sel = dmux_4way_unit->input.sel[0];
  dmux_chip(&dmux_unit_2);

  dmux_unit_3.input.in = dmux_unit_1.output.b;
  dmux_unit_3.input.sel = dmux_4way_unit->input.sel[0];
  dmux_chip(&dmux_unit_3);

  dmux_4way_unit->output.a = dmux_unit_2.output.a;
  dmux_4way_unit->output.b = dmux_unit_2.output.b;
  dmux_4way_unit->output.c = dmux_unit_3.output.a;
  dmux_4way_unit->output.d = dmux_unit_3.output.b;
}

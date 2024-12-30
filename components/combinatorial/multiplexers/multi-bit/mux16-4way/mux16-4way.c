#include <string.h>
#include "mux16-4way.h"
#include "mux16.h"
#include "types.h"

/*
 * out = a if sel = 00
 *       b if sel = 01
 *       c if sel = 10
 *       d if sel = 11
 */
void mux16_4way_chip(Mux16_4way *mux16_4way_unit)
{
  Mux16 mux16_unit_1, mux16_unit_2, mux16_unit_3;

  mux16_unit_1.input.sel = mux16_4way_unit->input.sel[0];
  memcpy(mux16_unit_1.input.a, mux16_4way_unit->input.a, sizeof(mux16_4way_unit->input.a));
  memcpy(mux16_unit_1.input.b, mux16_4way_unit->input.b, sizeof(mux16_4way_unit->input.b));
  mux16_chip(&mux16_unit_1);

  mux16_unit_2.input.sel = mux16_4way_unit->input.sel[0];
  memcpy(mux16_unit_2.input.a, mux16_4way_unit->input.c, sizeof(mux16_4way_unit->input.c));
  memcpy(mux16_unit_2.input.b, mux16_4way_unit->input.d, sizeof(mux16_4way_unit->input.d));
  mux16_chip(&mux16_unit_2);

  mux16_unit_3.input.sel = mux16_4way_unit->input.sel[1];
  memcpy(mux16_unit_3.input.a, mux16_unit_1.output.out, sizeof(mux16_unit_3.input.a));
  memcpy(mux16_unit_3.input.b, mux16_unit_2.output.out, sizeof(mux16_unit_3.input.b));
  mux16_chip(&mux16_unit_3);

  memcpy(mux16_4way_unit->output.out, mux16_unit_3.output.out, sizeof(mux16_4way_unit->output.out));
}

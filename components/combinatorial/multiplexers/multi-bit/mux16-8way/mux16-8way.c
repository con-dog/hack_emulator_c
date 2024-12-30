#include <string.h>
#include "mux16-8way.h"
#include "mux16-4way.h"
#include "mux16.h"
#include "types.h"

/*
 * out = a if sel = 000
 *       b if sel = 001
 *       c if sel = 010
 *       d if sel = 011
 *       e if sel = 100
 *       f if sel = 101
 *       g if sel = 110
 *       h if sel = 111
 */
void mux16_8way_chip(Mux16_8way *mux16_8way_unit)
{
  Mux16_4way mux16_4way_unit_1, mux16_4way_unit_2;
  Mux16 mux16_unit;

  memcpy(mux16_4way_unit_1.input.sel, mux16_8way_unit->input.sel, sizeof(mux16_4way_unit_1.input.sel));
  memcpy(mux16_4way_unit_1.input.a, mux16_8way_unit->input.a, sizeof(mux16_4way_unit_1.input.a));
  memcpy(mux16_4way_unit_1.input.b, mux16_8way_unit->input.b, sizeof(mux16_4way_unit_1.input.b));
  memcpy(mux16_4way_unit_1.input.c, mux16_8way_unit->input.c, sizeof(mux16_4way_unit_1.input.c));
  memcpy(mux16_4way_unit_1.input.d, mux16_8way_unit->input.d, sizeof(mux16_4way_unit_1.input.d));
  mux16_4way_chip(&mux16_4way_unit_1);

  memcpy(mux16_4way_unit_2.input.sel, mux16_8way_unit->input.sel, sizeof(mux16_4way_unit_2.input.sel));
  memcpy(mux16_4way_unit_2.input.a, mux16_8way_unit->input.e, sizeof(mux16_4way_unit_2.input.a));
  memcpy(mux16_4way_unit_2.input.b, mux16_8way_unit->input.f, sizeof(mux16_4way_unit_2.input.b));
  memcpy(mux16_4way_unit_2.input.c, mux16_8way_unit->input.g, sizeof(mux16_4way_unit_2.input.c));
  memcpy(mux16_4way_unit_2.input.d, mux16_8way_unit->input.h, sizeof(mux16_4way_unit_2.input.d));
  mux16_4way_chip(&mux16_4way_unit_2);

  mux16_unit.input.sel = mux16_8way_unit->input.sel[2];
  memcpy(mux16_unit.input.a, mux16_4way_unit_1.output.out, sizeof(mux16_unit.input.a));
  memcpy(mux16_unit.input.b, mux16_4way_unit_2.output.out, sizeof(mux16_unit.input.b));
  mux16_chip(&mux16_unit);

  memcpy(mux16_8way_unit->output.out, mux16_unit.output.out, sizeof(mux16_8way_unit->output.out));
}

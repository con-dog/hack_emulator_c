#include <string.h>
#include "mux16-8-way.h"
#include "mux16-4-way.h"
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
void mux16_8_way_chip(Mux16_8_Way *mux16_8_way)
{
  Mux16_4_Way mux16_4_way_chip_a, mux16_4_way_chip_b;
  Mux16 mux16_chip_c;

  // Mux a
  memcpy(mux16_4_way_chip_a.input.sel, mux16_8_way->input.sel, sizeof(mux16_4_way_chip_a.input.sel));
  memcpy(mux16_4_way_chip_a.input.a, mux16_8_way->input.a, sizeof(mux16_4_way_chip_a.input.a));
  memcpy(mux16_4_way_chip_a.input.b, mux16_8_way->input.b, sizeof(mux16_4_way_chip_a.input.b));
  memcpy(mux16_4_way_chip_a.input.c, mux16_8_way->input.c, sizeof(mux16_4_way_chip_a.input.c));
  memcpy(mux16_4_way_chip_a.input.d, mux16_8_way->input.d, sizeof(mux16_4_way_chip_a.input.d));
  mux16_4_way_chip(&mux16_4_way_chip_a);

  // Mux b
  memcpy(mux16_4_way_chip_b.input.sel, mux16_8_way->input.sel, sizeof(mux16_4_way_chip_b.input.sel));
  memcpy(mux16_4_way_chip_b.input.a, mux16_8_way->input.e, sizeof(mux16_4_way_chip_b.input.a));
  memcpy(mux16_4_way_chip_b.input.b, mux16_8_way->input.f, sizeof(mux16_4_way_chip_b.input.b));
  memcpy(mux16_4_way_chip_b.input.c, mux16_8_way->input.g, sizeof(mux16_4_way_chip_b.input.c));
  memcpy(mux16_4_way_chip_b.input.d, mux16_8_way->input.h, sizeof(mux16_4_way_chip_b.input.d));
  mux16_4_way_chip(&mux16_4_way_chip_b);

  // Mux c
  mux16_chip_c.input.sel = mux16_8_way->input.sel[2];
  memcpy(mux16_chip_c.input.a, mux16_4_way_chip_a.output.out, sizeof(mux16_chip_c.input.a));
  memcpy(mux16_chip_c.input.b, mux16_4_way_chip_b.output.out, sizeof(mux16_chip_c.input.b));
  mux16_chip(&mux16_chip_c);

  memcpy(mux16_8_way->output.out, mux16_chip_c.output.out, sizeof(mux16_8_way->output.out));
}

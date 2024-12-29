#include <string.h>
#include "mux16-4-way.h"
#include "mux16.h"
#include "types.h"

/*
 * out = a if sel = 00
 *       b if sel = 01
 *       c if sel = 10
 *       d if sel = 11
 */
void mux16_4_way_chip(Mux16_4_Way *mux16_4_way)
{
  Mux16 mux16_a, mux16_b, mux16_c;
  // Mux a
  mux16_a.input.sel = mux16_4_way->input.sel[0];
  memcpy(mux16_a.input.a, mux16_4_way->input.a, sizeof(mux16_4_way->input.a));
  memcpy(mux16_a.input.b, mux16_4_way->input.b, sizeof(mux16_4_way->input.b));
  mux16_chip(&mux16_a);

  // Mux b
  mux16_b.input.sel = mux16_4_way->input.sel[0];
  memcpy(mux16_b.input.a, mux16_4_way->input.c, sizeof(mux16_4_way->input.c));
  memcpy(mux16_b.input.b, mux16_4_way->input.d, sizeof(mux16_4_way->input.d));
  mux16_chip(&mux16_b);

  // Mux c
  mux16_c.input.sel = mux16_4_way->input.sel[1];
  memcpy(mux16_c.input.a, mux16_a.output.out, sizeof(mux16_c.input.a));
  memcpy(mux16_c.input.b, mux16_b.output.out, sizeof(mux16_c.input.b));
  mux16_chip(&mux16_c);

  // out
  memcpy(mux16_4_way->output.out, mux16_c.output.out, sizeof(mux16_4_way->output.out));
}

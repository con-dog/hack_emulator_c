#include "mux16.h"
#include "mux.h"
#include "types.h"

void mux16_chip(Mux16 *mux16_unit)
{
  Mux mux_units[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    mux_units[i].input.a = mux16_unit->input.a[i];
    mux_units[i].input.b = mux16_unit->input.b[i];
    mux_units[i].input.sel = mux16_unit->input.sel;
    mux_chip(&mux_units[i]);
    mux16_unit->output.out[i] = mux_units[i].output.out;
  }
}

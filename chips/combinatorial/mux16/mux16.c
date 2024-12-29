#include "mux16.h"
#include "mux.h"
#include "types.h"

void mux16_chip(Mux16 *mux16)
{
  Mux mux_chips[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    mux_chips[i].input.a = mux16->input.a[i];
    mux_chips[i].input.b = mux16->input.b[i];
    mux_chips[i].input.sel = mux16->input.sel;
    mux_gate(&mux_chips[i]);
    mux16->output.out[i] = mux_chips[i].output.out;
  }
}

#include <string.h>
#include "inc16.h"
#include "add16.h"

/**
 * 16-bit incrementer:
 * out = in + 1
 */
void inc16_chip(Inc16 *inc16_unit)
{
  Add16 add16_unit = {
      .input.a = inc16_unit->input.a,
      .input.b = {[0] = 1, [1 ... WORD_SIZE - 1] = 0},
  };
  add16_chip(&add16_unit);
  memcpy(inc16_unit->output.out, add16_unit.output.out, sizeof(inc16_unit->output.out));
}

#include "add16.h"
#include "full-adder.h"

/**
 * 16-bit adder: Adds two 16-bit two's complement values.
 * The most significant carry bit is ignored.
 */
void add16_chip(Add16 *add16_unit)
{
  Full_Adder full_adder_units[WORD_SIZE];
  for (int i = 0; i < WORD_SIZE; i++)
  {
    full_adder_units[i].input.a = add16_unit->input.a[0];
    full_adder_units[i].input.b = add16_unit->input.b[0];
    if (i == 0)
    {
      full_adder_units[i].input.c = 0;
    }
    else
    {
      full_adder_units[i].input.c = full_adder_units[i - 1].output.carry;
    }
    full_adder_chip(&full_adder_units[i]);
    add16_unit->output.out[i] = full_adder_units[i].output.sum;
  }
}

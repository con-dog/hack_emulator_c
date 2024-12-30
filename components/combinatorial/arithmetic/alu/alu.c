#include <string.h>
#include "alu.h"
#include "mux16.h"
#include "not16.h"
#include "and16.h"
#include "add16.h"
#include "or-8way.h"
#include "or.h"
#include "not.h"
#include "types.h"

/**
 * ALU (Arithmetic Logic Unit):
 * Computes out = one of the following functions:
 *                0, 1, -1,
 *                x, y, !x, !y, -x, -y,
 *                x + 1, y + 1, x - 1, y - 1,
 *                x + y, x - y, y - x,
 *                x & y, x | y
 * on the 16-bit inputs x, y,
 * according to the input bits zx, nx, zy, ny, f, no.
 * In addition, computes the two output bits:
 * if (out == 0) zr = 1, else zr = 0
 * if (out < 0)  ng = 1, else ng = 0
 */
// Implementation: Manipulates the x and y inputs
// and operates on the resulting values, as follows:
// if (zx == 1) sets x = 0        // 16-bit constant
// if (nx == 1) sets x = !x       // bitwise not
// if (zy == 1) sets y = 0        // 16-bit constant
// if (ny == 1) sets y = !y       // bitwise not
// if (f == 1)  sets out = x + y  // integer 2's complement addition
// if (f == 0)  sets out = x & y  // bitwise and
// if (no == 1) sets out = !out   // bitwise not
void alu_chip(Alu *alu)
{
  /*
   * INPUTS
   * X PRESETS
   */
  // ZERO X
  Mux16 mux16_block_x = {
      .input.b = {[0 ... WORD_SIZE - 1] = 0},
      .input.sel = alu->input.zx,
  };
  memcpy(mux16_block_x.input.a, alu->input.x, sizeof(mux16_block_x.input.a));
  mux16_chip(&mux16_block_x);

  // NOT X
  Not16 not16_block_x;
  memcpy(not16_block_x.input.in, mux16_block_x.output.out, sizeof(not16_block_x.input.in));
  not16_gate(&not16_block_x);

  // X BLOCK OUT
  Mux16 mux16_block_x_out = {
      .input.sel = alu->input.nx};
  memcpy(mux16_block_x_out.input.a, mux16_block_x.output.out, sizeof(mux16_block_x_out.input.a));
  memcpy(mux16_block_x_out.input.b, not16_block_x.output.out, sizeof(mux16_block_x_out.input.b));
  mux16_chip(&mux16_block_x_out);

  /*
   * Y PRESETS
   */
  // ZERO Y
  Mux16 mux16_block_y = {
      .input.b = {[0 ... WORD_SIZE - 1] = 0},
      .input.sel = alu->input.zy,
  };
  memcpy(mux16_block_y.input.a, alu->input.y, sizeof(mux16_block_y.input.a));
  mux16_chip(&mux16_block_y);

  // NOT Y
  Not16 not16_block_y;
  memcpy(not16_block_y.input.in, mux16_block_y.output.out, sizeof(not16_block_y.input.in));
  not16_gate(&not16_block_y);

  // Y BLOCK OUT
  Mux16 mux16_block_y_out = {
      .input.sel = alu->input.ny};
  memcpy(mux16_block_y_out.input.a, mux16_block_y.output.out, sizeof(mux16_block_y_out.input.a));
  memcpy(mux16_block_y_out.input.b, not16_block_y.output.out, sizeof(mux16_block_y_out.input.b));
  mux16_chip(&mux16_block_y_out);

  /*
   * HANDLE F
   */
  And16 and16_block_f;
  memcpy(and16_block_f.input.a, mux16_block_x_out.output.out, sizeof(and16_block_f.input.a));
  memcpy(and16_block_f.input.b, mux16_block_y_out.output.out, sizeof(and16_block_f.input.b));
  and16_gate(&and16_block_f);

  Add16 add16_block_f;
  memcpy(add16_block_f.input.a, mux16_block_x_out.output.out, sizeof(add16_block_f.input.a));
  memcpy(add16_block_f.input.b, mux16_block_y_out.output.out, sizeof(add16_block_f.input.b));
  add16_chip(&add16_block_f);

  // CHOOSE function
  Mux16 mux16_block_f_out = {
      .input.sel = alu->input.f,
  };
  memcpy(mux16_block_f_out.input.a, and16_block_f.output.out, sizeof(mux16_block_f_out.input.a));
  memcpy(mux16_block_f_out.input.b, add16_block_f.output.out, sizeof(mux16_block_f_out.input.b));
  mux16_chip(&mux16_block_f_out);

  /*
   * OUTPUTS
   * NO
   */
  Not16 not16_block_no;
  memcpy(not16_block_no.input.in, mux16_block_f_out.output.out, sizeof(not16_block_no.input.in));
  not16_gate(&not16_block_no);

  Mux16 mux16_block_no_out = {
      .input.sel = alu->input.no,
  };
  memcpy(mux16_block_no_out.input.a, mux16_block_f_out.output.out, sizeof(mux16_block_no_out.input.a));
  memcpy(mux16_block_no_out.input.b, not16_block_no.output.out, sizeof(mux16_block_no_out.input.b));
  mux16_chip(&mux16_block_no_out);

  // ALU OUT
  memcpy(alu->output.out, mux16_block_no_out.output.out, sizeof(alu->output.out));
  alu->output.ng = alu->output.out[15];

  /*
   * ZR
   */
  Or_8way or_8way_block_1, or_8way_block_2;
  memcpy(or_8way_block_1.input.in, &alu->output.out[0], sizeof(or_8way_block_1.input.in));
  memcpy(or_8way_block_2.input.in, &alu->output.out[8], sizeof(or_8way_block_2.input.in));
  or_8way_gate(&or_8way_block_1);
  or_8way_gate(&or_8way_block_2);

  Or or_unit = {
      .input.a = or_8way_block_1.output.out,
      .input.b = or_8way_block_2.output.out,
  };
  or_gate(&or_unit);

  Not not_unit = {
      .input.in = or_unit.output.out,
  };
  not_gate(&not_unit);

  alu->output.zr = not_unit.output.out;
}
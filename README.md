# Summary
NandToTetris is a course which has you build a full computer from "scratch":

Logic gates -> Chips -> RAM -> CPU -> Computer
-> Assembler -> Compiler -> OS -> Tetris

All this is done via software defined hardware emulation.

*I'm building an emulator for this entire stack in C.*

## Difference to other Emulator projects
- No external dependencies (so far)
- Start with a single software defined NAND gate in C
  - EVERYTHING is built from this base chip - everything
- Don't use certain programming utilities: boolean logic operators, bitwise logic operators etc 
  - Instead we leverage the gates/chips to implement such logic
- Build more and more base chips from the NAND gate
  - Simple gates: OR, AND, NOT, XOR
  - Simple chips: DMux, Mux
  - 16 bit variants

For comparison, most emulator projects start right at the CPU level and don't sequentially build primitive structures
- They look at CPU truth table / Instruction set and implement that logic directly
- More straight forward, but you skip all the gates/chips fun.

## Contributing [OPEN]
A really simple way to start contributing would be to write some truth table tests for the nand_gate, then the other base gates too.

Anyone can do this, its pretty easy stuff :)

EG: For the NAND gate, it would be as simple as the following (pseudocode):
```c
// Truth Table for NAND Gate:
/* 
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */

// Define gate
Nand nand_instance;

// Set inputs to either 0 or 1
nand_instance.input.a = 0;
nand_instance.input.b = 0;

// Process logic
nand_gate(&nand_instance);

// Check output is correct
if (nand_instance.output.out == 1)
{
  // PASSED
}
else
{
  // FAILED
}
```

## Example code, what to expect

Confused? Some code example may help.

### Simple Gates

#### NAND Gate
Heres example code for my NAND gate:

```c
/*
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */

typedef struct Nand_Input
{
  bool a;
  bool b;
} Nand_Input;

typedef struct Nand_Output
{
  bool out;
} Nand_Output;

typedef struct Nand
{
  Nand_Input input;
  Nand_Output output;
} Nand;

void nand_gate(Nand *nand_unit)
{
  nand_unit->output.out = !(nand_unit->input.a & nand_unit->input.b);
}
```

#### NOT Gate
From this gate I build a NOT gate (note, no boolean operators)

```c
typedef struct Not_Input
{
  bool in;
} Not_Input;

typedef struct Not_Output
{
  bool out;
} Not_Output;

typedef struct Not
{
  Not_Input input;
  Not_Output output;
} Not;

void not_gate(Not *not_unit)
{
  Nand nand_unit = {
      .input.a = not_unit->input.in,
      .input.b = not_unit->input.in,
  };
  nand_gate(&nand_unit);
  not_unit->output.out = nand_unit.output.out;
}
```
    
Then OR / AND / XOR / MUX / DMUX ..... and their 16 bit versions.

### Combinatorial Chips
#### 8-way DMUX
Heres a more complex chip, a 8-way DMux

```c
/*
 * [a, b, c, d, e, f, g, h] = [in, 0,  0,  0,  0,  0,  0,  0] if sel = 000
 *                            [0, in,  0,  0,  0,  0,  0,  0] if sel = 001
 *                            [0,  0, in,  0,  0,  0,  0,  0] if sel = 010
 *                            [0,  0,  0, in,  0,  0,  0,  0] if sel = 011
 *                            [0,  0,  0,  0, in,  0,  0,  0] if sel = 100
 *                            [0,  0,  0,  0,  0, in,  0,  0] if sel = 101
 *                            [0,  0,  0,  0,  0,  0, in,  0] if sel = 110
 *                            [0,  0,  0,  0,  0,  0,  0, in] if sel = 111
 */

typedef struct Dmux_8way_Input
{
  bool in;
  bool sel[3];
} Dmux_8way_Input;

typedef struct Dmux_8way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
  bool e;
  bool f;
  bool g;
  bool h;
} Dmux_8way_Output;

typedef struct Dmux_8way
{
  Dmux_8way_Input input;
  Dmux_8way_Output output;
} Dmux_8way;

void dmux_8way_chip(Dmux_8way *dmux_8way_unit)
{
  Dmux dmux_unit;
  Dmux_4way dmux_4way_unit_1, dmux_4way_unit_2;

  // dmux
  dmux_unit.input.in = dmux_8way_unit->input.in;
  dmux_unit.input.sel = dmux_8way_unit->input.sel[2];
  dmux_chip(&dmux_unit);

  dmux_4way_unit_1.input.in = dmux_unit.output.a;
  memcpy(dmux_4way_unit_1.input.sel, dmux_8way_unit->input.sel, sizeof(dmux_4way_unit_1.input.sel));
  dmux_4way_chip(&dmux_4way_unit_1);

  dmux_4way_unit_2.input.in = dmux_unit.output.b;
  memcpy(dmux_4way_unit_2.input.sel, dmux_8way_unit->input.sel, sizeof(dmux_4way_unit_2.input.sel));
  dmux_4way_chip(&dmux_4way_unit_2);

  dmux_8way_unit->output.a = dmux_4way_unit_1.output.a;
  dmux_8way_unit->output.b = dmux_4way_unit_1.output.b;
  dmux_8way_unit->output.c = dmux_4way_unit_1.output.c;
  dmux_8way_unit->output.d = dmux_4way_unit_1.output.d;
  dmux_8way_unit->output.e = dmux_4way_unit_2.output.a;
  dmux_8way_unit->output.f = dmux_4way_unit_2.output.b;
  dmux_8way_unit->output.g = dmux_4way_unit_2.output.c;
  dmux_8way_unit->output.h = dmux_4way_unit_2.output.d;
}
```

#### 16-bit 8 way Mux
```c
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

typedef struct Mux16_8way_Input
{
  bool a[WORD_SIZE];
  bool b[WORD_SIZE];
  bool c[WORD_SIZE];
  bool d[WORD_SIZE];
  bool e[WORD_SIZE];
  bool f[WORD_SIZE];
  bool g[WORD_SIZE];
  bool h[WORD_SIZE];
  bool sel[3];
} Mux16_8way_Input;

typedef struct Mux16_8way_Output
{
  bool out[WORD_SIZE];
} Mux16_8way_Output;

typedef struct Mux16_8way
{
  Mux16_8way_Input input;
  Mux16_8way_Output output;
} Mux16_8way;

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
```

## Progress
I have only started this project yesterday, so have completed 1 out of 7 hardware projects so far. 
I plan to build out the full PC this way, then begin work writing an Assembler in C.

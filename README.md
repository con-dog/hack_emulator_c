# Summary
NandToTetris is a course which has you build a full computer from "scratch":

Logic gates -> Chips -> RAM -> CPU -> Computer
-> Assembler -> Compiler -> OS -> Tetris

All this is done via software defined hardware emulation.

*I'm building an emulator for this entire stack in C.*

## Difference to other Emulator projects
- No external dependencies (so far)
- Start with a single software defined NAND gate in C
  - EVERYTHING is built from this base chip
- Don't use certain programming utilities: boolean logic operators, bitwise logic operators etc 
  - Instead we leverage the gates/chips to implement such logic
- I build more and more base chips from the NAND gate
  - Simple gates: OR, AND, NOT, XOR
  - Simple chips: DMux, Mux
  - 16 bit variants

For comparison, most emulator projects start right at the CPU level and don't sequentially build primitive structures
- They look at CPU truth table / Instruction set and implement that logic directly
- More straight forward, but you skip all the gates/chips fun.

## Example code, what to expect

Confused? Some code example may help.

### Simple Gates

#### NAND Gate
Heres example code for my NAND gate:


```c
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

void nand_gate(Nand *nand)
{
  nand->output.out = !(nand->input.a & nand->input.b);
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

void not_gate(Not * not )
{
  Nand nand = {
      .input.a = not ->input.in,
      .input.b = not ->input.in,
  };
  nand_gate(&nand);
  not ->output.out = nand.output.out;
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

typedef struct Dmux_8_Way_Input
{
  bool in;
  bool sel[3];
} Dmux_8_Way_Input;

typedef struct Dmux_8_Way_Output
{
  bool a;
  bool b;
  bool c;
  bool d;
  bool e;
  bool f;
  bool g;
  bool h;
} Dmux_8_Way_Output;

typedef struct Dmux_8_Way
{
  Dmux_8_Way_Input input;
  Dmux_8_Way_Output output;
} Dmux_8_Way;

void dmux_8_way_chip(Dmux_8_Way *dmux_8_way)
{
  Dmux dmux;
  Dmux_4_Way dmux_4_way_a, dmux_4_way_b;

  // dmux
  dmux.input.in = dmux_8_way->input.in;
  dmux.input.sel = dmux_8_way->input.sel[2];
  dmux_chip(&dmux);

  // dmux 4way a
  dmux_4_way_a.input.in = dmux.output.a;
  memcpy(dmux_4_way_a.input.sel, dmux_8_way->input.sel, sizeof(dmux_4_way_a.input.sel));
  dmux_4_way_chip(&dmux_4_way_a);

  // dmux 4way b
  dmux_4_way_b.input.in = dmux.output.b;
  memcpy(dmux_4_way_b.input.sel, dmux_8_way->input.sel, sizeof(dmux_4_way_b.input.sel));
  dmux_4_way_chip(&dmux_4_way_b);

  // output
  dmux_8_way->output.a = dmux_4_way_a.output.a;
  dmux_8_way->output.b = dmux_4_way_a.output.b;
  dmux_8_way->output.c = dmux_4_way_a.output.c;
  dmux_8_way->output.d = dmux_4_way_a.output.d;
  dmux_8_way->output.e = dmux_4_way_b.output.a;
  dmux_8_way->output.f = dmux_4_way_b.output.b;
  dmux_8_way->output.g = dmux_4_way_b.output.c;
  dmux_8_way->output.h = dmux_4_way_b.output.d;
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

typedef struct Mux16_8_Way_Input
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
} Mux16_8_Way_Input;

typedef struct Mux16_8_Way_Output
{
  bool out[WORD_SIZE];
} Mux16_8_Way_Output;

typedef struct Mux16_8_Way
{
  Mux16_8_Way_Input input;
  Mux16_8_Way_Output output;
} Mux16_8_Way;

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


```

## Progress
I have only started this project yesterday, so have completed 1 out of 7 hardware projects so far. 
I plan to build out the full PC this way, then begin work writing an Assembler in C.

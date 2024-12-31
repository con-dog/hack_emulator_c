# Testing

## Logic Tests
### Running Logic Tests
From root of project, run the following commands to compile and run all tests:
```bash
# Compile all tests
make test
# Run all tests
./test
```

### Adding Logic Tests
Inside each component directory, simply add a new file called `test-<component_name>.h` and `test-<component_name>.c` and write your tests in there.

Heres an example of a test for the NAND gate:
```c
// Truth Table
/*
 * | a | b | out |
 * ---------------
 * | 0 | 0 |  1  |
 * | 0 | 1 |  1  |
 * | 1 | 0 |  1  |
 * | 1 | 1 |  0  |
 */
#include <stdio.h>

#include "test-nand.h"
#include "nand.h"
#include "test-utils.h"

void test_nand(Test_Counter *counter)
{
  // Truth table for NAND: expected outputs
  const int expected[4] = {1, 1, 1, 0}; // outputs for (0,0), (0,1), (1,0), (1,1)
  for (int i = 0; i < 4; i++)
  {
    Nand nand = {
        .input.a = (i >> 1) & 1, // Gets first bit  (0011)
        .input.b = i & 1,        // Gets second bit (0101)
    };
    nand_gate(&nand);
    test_assert(nand.output.out == expected[i], counter,
                "NAND(%d,%d) should be %d",
                nand.input.a,
                nand.input.b,
                expected[i]);
  }
}
```

The next step to get tests running is to add the test to the `test.c` file in the root of the project. This file is used to compile all tests and run them. Simply add the test function to the `main` function in `test.c` like so:
```c
int main(void)
{
  Test_Counter counter = {
      .tests_failed = 0,
      .tests_run = 0,
  };

  /*
   * START: ADD ALL TESTS IN HERE
   */
  test_nand(&counter);
  // NEXT TEST GOES HERE
  /*
   * END: ADD ALL TESTS IN HERE
   */

  printf("\nTests run: \t%d\nTests failing: \t%d\n", counter.tests_run, counter.tests_failed);
}
```
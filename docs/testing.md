# Testing

## Logic Tests
### Running Logic Tests
From root of project, run the following commands to compile and run all tests:
```bash
# Compile all tests
make tests
# Run all tests
./tests
```

### Adding Logic Tests
Inside each component directory, simply add a new file called <component_name>_test.c and write your tests in there.
```c
#include "nand.h"
#include <assert.h>

int main()
{
  // Define gate
  Nand nand_instance;

  // Set inputs to either 0 or 1
  nand_instance.input.a = 0;
  nand_instance.input.b = 0;

  // Process logic
  nand_gate(&nand_instance);

  // Check output is correct
  assert(nand_instance.output.out == 1);
}
```

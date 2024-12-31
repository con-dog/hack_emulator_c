#include <stdio.h>
#include <stdbool.h>
#include "test-utils.h"
#include "test-nand.h"

int main(void)
{
  Test_Counter counter = {
      .tests_failed = 0,
      .tests_run = 0,
  };

  test_nand(&counter);
  printf("\nTests run: \t%d\nTests failing: \t%d\n", counter.tests_run, counter.tests_failed);
}
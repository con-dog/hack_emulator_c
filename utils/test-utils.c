#include <stdarg.h>
#include <stdio.h>
#include "test-utils.h"

void test_assert(bool condition, Test_Counter *counter, const char *format, ...)
{
  counter->tests_run++;

  // Handle variable arguments for formatted string
  va_list args;
  va_start(args, format);

  if (!condition)
  {
    counter->tests_failed++;
    printf("❌ FAIL: ");
    vprintf(format, args);
    printf("\n");
  }
  else
  {
    printf("✅ PASS: ");
    vprintf(format, args);
    printf("\n");
  }

  va_end(args);
}
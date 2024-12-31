#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdbool.h>

typedef struct Test_Counter
{
  int tests_run;
  int tests_failed;
} Test_Counter;

void test_assert(bool condition, Test_Counter *counter, const char *format, ...);

#endif
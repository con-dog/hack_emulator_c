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

#include "nand-test.h"
#include "nand.h"

void nand_test(void)
{
    // Define Gate
    Nand nand_instance;

    //---------------
    // Test 1
    //---------------

    // Set input values
    nand_instance.input.a = 0;
    nand_instance.input.b = 0;

    // Evaluate
    nand_gate(&nand_instance);

    // Check output
    if (nand_instance.output.out == 1)
    {
        printf("Test 1 PASSED");
    }
    else
    {
        printf("Test 1 FAILED");
    }

    //---------------
    // Test 2
    //---------------

    // Set input values
    nand_instance.input.a = 0;
    nand_instance.input.b = 1;

    // Evaluate
    nand_gate(&nand_instance);

    // Check output
    if (nand_instance.output.out == 1)
    {
        printf("Test 2 PASSED");
    }
    else
    {
        printf("Test 2 FAILED");
    }

    //---------------
    // Test 3
    //---------------

    // Set input values
    nand_instance.input.a = 1;
    nand_instance.input.b = 0;

    // Evaluate
    nand_gate(&nand_instance);

    // Check output
    if (nand_instance.output.out == 1)
    {
        printf("Test 3 PASSED");
    }
    else
    {
        printf("Test 3 FAILED");
    }

    //---------------
    // Test 4
    //---------------

    // Set input values
    nand_instance.input.a = 1;
    nand_instance.input.b = 1;

    // Evaluate
    nand_gate(&nand_instance);

    // Check output
    if (nand_instance.output.out == 0)
    {
        printf("Test 4 PASSED");
    }
    else
    {
        printf("Test 4 FAILED");
    }
}
#include <stdio.h>

int main() 
{
    int x = 3, y = 4, z;

    /* 
     * 1. Nested Ternary Operator:
     * This evaluates conditions inside other conditions.
     * 
     * Step-by-Step Breakdown:
     * - Step 1: Check outer condition (x == 3). This is TRUE because x is 3.
     * - Step 2: Because it's true, enter the inner ternary: (y == 4 ? 6 : 8).
     * - Step 3: Check inner condition (y == 4). This is TRUE because y is 4.
     * - Step 4: The inner ternary evaluates to 6.
     * - Step 5: 6 is assigned to 'z'.
     * 
     * Note: If 'x' was not 3, it would jump straight to the very end and assign 0.
     */
    z = (x == 3 ? (y == 4 ? 6 : 8) : 0);

    // Output: 6
    printf("%d\n", z);

    return 0;
}

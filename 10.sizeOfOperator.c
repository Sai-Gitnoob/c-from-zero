#include <stdio.h>

int main() 
{
    int x;

    /* 
     * The sizeof operator returns the size of a data type or variable in bytes.
     * Note: The standard format specifier for sizeof is %lu (unsigned long) 
     * or %zu, but %d is frequently used in classroom examples for simplicity.
     */

    // 1. Evaluates the size of a variable name (integer variable) -> Output: 4
    printf("%d\n", sizeof(x));

    // 2. Evaluates the primitive integer data type directly -> Output: 4
    printf("%d\n", sizeof(int));

    // 3. Evaluates an integer constant literal (defaults to int) -> Output: 4
    printf("%d\n", sizeof(5));

    // 4. Evaluates a single character byte size -> Output: 1
    printf("%d\n", sizeof(char));

    // 5. Evaluates a short integer byte size -> Output: 2
    printf("%d\n", sizeof(short int));

    // 6. Evaluates a single-precision floating-point size -> Output: 4
    printf("%d\n", sizeof(float));

    // 7. Evaluates a double-precision floating-point size -> Output: 8
    printf("%d\n", sizeof(double));

    // 8. Evaluates an extended-precision floating-point size -> Output: 12 or 16
    printf("%d\n", sizeof(long double));

    return 0;
}

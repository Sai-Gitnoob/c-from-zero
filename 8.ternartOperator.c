#include <stdio.h>

int main() 
{
    int x, y, max;

    // 1. Prompt the user for input
    printf("Enter values of x and y:\n");
    scanf("%d%d", &x, &y);

    /* 
     * 2. Ternary Operator (Conditional Operator) Syntax:
     * Condition ? Expression_If_True : Expression_If_False;
     * 
     * How it works here:
     * Evaluates if 'x' is greater than 'y'.
     * If true (e.g., x = 20, y = 10), 'x' is evaluated and assigned to 'max'.
     * If false (e.g., x = 10, y = 20), 'y' is evaluated and assigned to 'max'.
     */
    max = (x > y) ? x : y;

    // 3. Output the larger value
    printf("Larger of %d and %d is %d\n", x, y, max);

    return 0;
}
 
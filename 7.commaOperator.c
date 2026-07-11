#include <stdio.h>

int main() 
{
    int a, b;

    /* 
     * 1. Comma operator inside parentheses:
     * Expressions are evaluated from left to right.
     * The value of the entire expression is the value of the rightmost operand.
     * Here, 2 is evaluated, then 3 is evaluated, and 3 is assigned to 'a'.
     */
    a = (2, 3); 

    /* 
     * 2. Comma operator without parentheses:
     * The assignment operator (=) has a higher precedence than the comma operator (,).
     * Therefore, 'b = 2' executes first, assigning 2 to 'b'.
     * Then the comma operator evaluates 4, which is discarded.
     */
    b = 2, 4;   

    // Output: a = 3, b = 2
    printf("%d, %d\n", a, b); 

    return 0;
}

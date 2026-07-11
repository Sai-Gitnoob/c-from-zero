#include <stdio.h>

int main() 
{
    int num1, num2;

    // 1. Read two integer values from the user
    scanf("%d %d", &num1, &num2);

    /* 
     * 2. Conditional control statement (if-else):
     * C evaluates conditions using numeric truth values:
     *   - 0 is treated as FALSE.
     *   - Any non-zero value (positive or negative) is treated as TRUE.
     * 
     * How it works here:
     * The relational expression (num1 > num2) returns 1 if true, and 0 if false.
     * Example: If num1 = 10 and num2 = 20:
     *   - (10 > 20) evaluates to 0 (FALSE).
     *   - The code skips the 'if' block and moves directly into the 'else' block.
     */
    if (num1 > num2) 
    {
        // Executes only if the condition evaluates to a non-zero value (TRUE)
        printf("%d is greater\n", num1);
    } 
    else 
    {
        // Executes if the condition evaluates to exactly 0 (FALSE)
        printf("%d is greater\n", num2);
    }

    return 0;
}

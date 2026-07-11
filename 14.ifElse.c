#include <stdio.h>

int main() {
    // 1. Initialize three test variables with matching values
    int n1 = 20, n2 = 20, n3 = 20;

    /* 
     * 2. Logical AND (&&) Evaluation:
     * Both conditions on the left and right must be TRUE (non-zero) 
     * for the entire expression to be true.
     * 
     * Step-by-Step Breakdown for n1=20, n2=20, n3=20:
     * - Check 1: (n1 >= n2) -> (20 >= 20) is TRUE.
     * - Check 2: (n1 >= n3) -> (20 >= 20) is TRUE.
     * Since both are true, the first block executes and the rest are skipped.
     */
    if (n1 >= n2 && n1 >= n3) 
    {
        printf("%d is the largest number.", n1);
    } 
    /* 
     * 3. Else If Branch:
     * This is only evaluated if the first 'if' condition fails.
     */
    else if (n2 >= n1 && n2 >= n3) 
    {
        printf("%d is the largest number.", n2);
    } 
    /* 
     * 4. Implicit Fallback Else:
     * Note: The professor omitted the literal 'else' keyword here in the final block,
     * but it functions as the ultimate fallback if both conditions above fail.
     */
    else 
    {
        printf("%d is the largest number.", n3);
    }

    return 0;
}

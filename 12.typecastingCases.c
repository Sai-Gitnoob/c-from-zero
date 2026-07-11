#include <stdio.h>

int main() 
{
    int a = 10, b = 3;
    float c;

    /* 
     * CASE 1: Pure Integer Division
     * Both 'a' and 'b' are integers, so integer division occurs first: 10 / 3 = 3.
     * The fractional part is lost BEFORE assignment.
     * Then, 3 is implicitly promoted to float during assignment.
     * Output: 3.000000
     */
    c = a / b;
    printf("Case 1 Result: %f\n", c);


    /* 
     * CASE 2: Correct Explicit Typecasting
     * Typecast operator '(float)' has higher precedence than division '/'.
     * 'a' is explicitly converted to 10.0 first.
     * Then, 'b' (3) is implicitly promoted to 3.0 to match the float.
     * A float division occurs: 10.0 / 3.0 = 3.333333.
     * Output: 3.333333
     */
    c = (float)a / b;
    printf("Case 2 Result: %f\n", c);


    /* 
     * CASE 3: Misplaced Parentheses
     * The parentheses force the integer division to happen first: (10 / 3) = 3.
     * The fractional part is completely lost inside the parentheses.
     * Then, '(float)' casts the remaining whole number integer 3 into 3.0.
     * Output: 3.000000
     */
    c = (float)(a / b);
    printf("Case 3 Result: %f\n", c);

    return 0;
}

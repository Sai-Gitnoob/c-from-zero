#include <stdio.h>

int main(void) {
    // === EXAMPLE 1: PREFIX OPERATORS (++a, --a) ===
    // Rule: Change the value first, then use it in the expression.
    int a = 5;
    printf("--- Prefix Example ---\n");
    printf("a=%d\n", a);     // Outputs: 5
    printf("a=%d\n", ++a);   // Increments to 6, then prints: 6
    printf("a=%d\n", a);     // Outputs: 6
    printf("a=%d\n", --a);   // Decrements to 5, then prints: 5
    printf("a=%d\n", a);     // Outputs: 5


    // === EXAMPLE 2: POSTFIX OPERATORS (a++, a--) ===
    // Rule: Use the current value in the expression first, then change it.
    a = 5; 
    printf("\n--- Postfix Example ---\n");
    printf("a=%d\n", a);     // Outputs: 5
    printf("a=%d\n", a++);   // Prints current value (5), then 'a' becomes 6
    printf("a=%d\n", a);     // Outputs: 6
    printf("a=%d\n", a--);   // Prints current value (6), then 'a' becomes 5
    printf("a=%d\n", a);     // Outputs: 5

    return 0;
}

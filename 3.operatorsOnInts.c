#include <stdio.h>

int main() {
    int x = 15;
    int y = 6;

    // Arithmetic Operations on Integers
    printf("Sum=%d\n", x + y);         // Outputs: Sum=21
    printf("Difference=%d\n", x - y);  // Outputs: Difference=9
    printf("Product=%d\n", x * y);     // Outputs: Product=90
    
    // Note: Integer division truncates the decimal part
    printf("Quotient=%d\n", x / y);    // Outputs: Quotient=2 (not 2.5)
    
    // Modulo operator returns the remainder
    printf("Remainder=%d\n", x % y);   // Outputs: Remainder=3

    return 0;
}

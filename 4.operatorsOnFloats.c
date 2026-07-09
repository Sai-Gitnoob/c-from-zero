#include <stdio.h>


int main(void) {
    float x = 5.8f;
    float y = 2.3f;

    // Arithmetic Operations on Floating-Point Numbers
    printf("Sum=%f\n", x + y);         // Outputs approx: 8.100000
    printf("Difference=%f\n", x - y);  // Outputs approx: 3.500000
    printf("Product=%f\n", x * y);     // Outputs approx: 13.340000
    
    // Floating-point division preserves the decimal precision
    printf("Quotient=%.3f\n", x / y);    // Outputs approx: 2.521739 (gives 3 decimal places cuz of %.3f)

    return 0;
}



#include <stdio.h>

int main() 
{
    /* 
     * 1. IMPLICIT TYPECASTING (Automatic Conversion)
     * Done automatically by the compiler. Smaller data types are promoted 
     * to larger data types to prevent data/information loss.
     */
    short x = 10;     // Typically 16-bit or smaller integer
    int y = 20;       // Typically 32-bit integer

    /*
     * The compiler automatically converts 'x' to an 'int' before adding.
     * The final result is computed as an 'int'. No data is lost.
     */
    int result = x + y; 


    /* 
     * 2. EXPLICIT TYPECASTING (Manual Conversion)
     * Forced by the programmer using the syntax: (target_type) variable;
     * Can lead to a loss of information when downgrading data types.
     */
    float my_float = 3.435;
    int my_int;

    /*
     * We manually cast 'my_float' to an 'int'. 
     * The fractional/decimal part (.435) is completely truncated (chopped off).
     * Only the whole number (3) is saved into 'my_int'.
     */
    my_int = (int)my_float; 

    // Output: Float value: 3.435000, Casted Int value: 3
    printf("Float value: %f, Casted Int value: %d\n", my_float, my_int);

    return 0;
}

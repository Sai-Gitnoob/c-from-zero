/* =========================================================================
 * TOPIC: HOW POINTERS WORK (BASIC MECHANICS)
 * Source: Gate Smashers (GATE Preparation Notes)
 * =========================================================================
 *
 * KEY DEFINITIONS:
 * ----------------
 * 1. Pointer: A special variable that stores the memory address of another variable.
 * 2. Address-of Operator (&): Retrieves the memory address where a variable is stored.
 * 3. Dereference Operator (*): Accesses or modifies the value located at the address 
 *    stored inside a pointer variable (Value at Address).
 */

#include <stdio.h>

void main() {
    // --- MEMORY LAYOUT SIMULATION ---
    // Let's assume:
    // Variable 'x' is allocated at Memory Address: 1000
    // Pointer variable 'y' is allocated at Memory Address: 2000

    int x = 10;      // Value 10 is stored at address 1000
    int *y = &x;     // 'y' is a pointer to an int, storing the address of 'x' (1000)

    /* ---------------------------------------------------------------------
     * OUTPUT EVALUATIONS FROM THE BOARD
     * --------------------------------------------------------------------- */

    // 1. Printing the direct value of x
    printf("%d\n", x);   
    // OUTPUT: 10

    // 2. Printing the address of x using the reference operator (&)
    printf("%u\n", &x);  
    // OUTPUT: 1000 (The address where variable 'x' resides)

    // 3. Printing the value inside pointer y (which is the address of x)
    printf("%u\n", y);   
    // OUTPUT: 1000 (Since y = &x)

    // 4. Dereferencing y: Accessing the value stored at the address contained in y
    printf("%d\n", *y);  
    // OUTPUT: 10 (Value at address 1000 is 10)

    // 5. Printing the unique memory address of the pointer variable itself
    printf("%u\n", &y);  
    // OUTPUT: 2000 (The physical address where the pointer 'y' is stored)
}

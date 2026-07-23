/* =========================================================================
 * TOPIC: AUTO STORAGE CLASS IN C
 * Source: Gate Smashers (GATE Preparation Notes)
 * =========================================================================
 *
 * 1. OVERVIEW & SYNTAX
 * --------------------
 * - 'auto' is the default storage class for all local variables in C.
 * - Syntax: 
 *     auto int a;  OR  int a;  (Both are identical)
 * - Memory Location: Stack
 * - Default Value: Garbage value (undefined)
 * - Scope: Local to the block/function in which it is defined.
 * - Lifetime: Local (created when block enters, destroyed when block exits).
 */

/* =========================================================================
 * 2. EXAMPLE 1: LIFETIME OF AUTO VARIABLES (Function Calls)
 * =========================================================================
 * Each call to fun() allocates a new instance of 'a' on the stack, 
 * increments it, prints it, and then destroys it upon function exit.
 */

#include <stdio.h>

void fun() {
    auto int a = 10; // re-allocated and initialized to 10 on every call
    ++a;
    printf("%d\n", a); 
}

void main() {
    fun(); // Outputs: 11 (allocated at address 100, then destroyed)
    fun(); // Outputs: 11 (allocated at address 200, then destroyed)
    fun(); // Outputs: 11 (allocated at address 300, then destroyed)
    
    // printf("%d", a); 
    // ERROR: 'a' is Undefined here because it is outside the scope of fun()
}

/* =========================================================================
 * 3. EXAMPLE 2: SCOPE OF AUTO VARIABLES (Nested Blocks)
 * =========================================================================
 * Variables in inner blocks shadow/hide variables with the same name in 
 * outer blocks. Inner blocks can access outer block variables if not shadowed.
 */

void main_example_2() {
    // --- BLOCK 1 (Outer) ---
    int a = 10, b = 20; // 'a' at addr 100, 'b' at addr 200

    {
        // --- BLOCK 2 (Nested) ---
        int a = 15, c = 18; // New 'a' shadows outer 'a'. 'c' is at addr 400.
        
        printf("%d, %d, %d\n", a, b, c); 
        // OUTPUT: 15, 20, 18 (Uses inner 'a', outer 'b', and inner 'c')

        {
            // --- BLOCK 3 (Deeply Nested) ---
            int b = 25, d = 30; // New 'b' shadows outer 'b'
            
            printf("%d, %d, %d, %d\n", a, b, c, d);
            // OUTPUT: 15, 25, 18, 30
        }

        // Back in BLOCK 2
        // printf("%d, %d, %d, %d\n", a, b, c, d);
        // OUTPUT: 15, 20, 18, UNDEFINED 
        // ('d' is destroyed when exiting BLOCK 3)
    }

    // Back in BLOCK 1
    // printf("%d, %d, %d, %d\n", a, b, c, d);
    // OUTPUT: 10, 20, UNDEFINED, UNDEFINED 
    // ('c' and 'd' are completely out of scope here)
}

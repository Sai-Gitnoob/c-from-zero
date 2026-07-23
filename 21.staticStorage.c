/* =========================================================================
 * TOPIC: STATIC STORAGE CLASS IN C
 * Source: Gate Smashers (GATE Preparation Notes)
 * =========================================================================
 *
 * 1. OVERVIEW & SYNTAX
 * --------------------
 * - 'static' variables retain their value even after they go out of scope.
 * - Syntax: 
 *     static int a;
 * - Default Value: Automatically initialized to 0 (unlike auto's garbage value).
 * - Memory Location: Data Segment (Static/Global memory).
 * - Scope: Local to the block/function in which it is defined.
 * - Lifetime: Throughout the execution of the entire program.
 */

/* =========================================================================
 * 2. EXAMPLE 1: LIFETIME OF STATIC VARIABLES (Reusing Memory)
 * =========================================================================
 * The initialization 'static int a = 10;' happens only ONCE at compile time.
 * Subsequent function calls reuse the same memory address, preserving modifications.
 */

#include <stdio.h>

void fun() {
    static int a = 10; // Initialized ONLY ONCE at the start of the program
    ++a;
    printf("%d\n", a); 
}

void main_example_1() {
    fun(); // Outputs: 11 (Variable at address 100 increments from 10 to 11)
    fun(); // Outputs: 12 (Variable at address 100 increments from 11 to 12)
    fun(); // Outputs: 13 (Variable at address 100 increments from 12 to 13)
    
    // printf("%d", a); 
    // ERROR: 'a' is Undefined here because its SCOPE is strictly local to fun().
}

/* =========================================================================
 * 3. EXAMPLE 2: STATIC VARIABLE IN RECURSION (GATE Conceptual Question)
 * =========================================================================
 * Because 'i' is static, a single instance is shared across all recursive frames.
 * Modifying 'i' in one recursive call affects its value in all other frames.
 */

int f(int n) {
    static int i = 1; // Persistent single instance across all recursion levels
    
    if (n >= 5) {
        return n;
    }
    
    n = n + i; 
    i++; 
    
    return f(n);
}

void main_example_2() {
    printf("%d\n", f(1)); // Outputs: 7
}

/* 
 * Trace of f(1):
 * -------------------------------------------------------------------------
 * Call 1: f(1) -> [n=1 (addr 100), static i=1 (addr 200)]
 *         - Check: 1 >= 5 (False)
 *         - n = 1 + 1 = 2
 *         - i++ -> i becomes 2
 *         - Calls f(2)
 * 
 * Call 2: f(2) -> [n=2 (addr 300), static i=2 (addr 200)]
 *         - Check: 2 >= 5 (False)
 *         - n = 2 + 2 = 4
 *         - i++ -> i becomes 3
 *         - Calls f(4)
 * 
 * Call 3: f(4) -> [n=4 (addr 400), static i=3 (addr 200)]
 *         - Check: 4 >= 5 (False)
 *         - n = 4 + 3 = 7
 *         - i++ -> i becomes 4
 *         - Calls f(7)
 * 
 * Call 4: f(7) -> [n=7 (addr 500), static i=4 (addr 200)]
 *         - Check: 7 >= 5 (True) -> Returns n (7)
 * 
 * Unwinding Phase:
 *         - Call 4 returns 7 to Call 3
 *         - Call 3 returns 7 to Call 2
 *         - Call 2 returns 7 to Call 1
 *         - Final Output = 7
 * -------------------------------------------------------------------------
 */

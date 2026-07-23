/* =========================================================================
 * TOPIC: DANGLING POINTERS IN C
 * Source: Gate Smashers (GATE Preparation Notes)
 * =========================================================================
 *
 * DEFINITION:
 * -----------
 * A Dangling Pointer is a pointer that points to a memory location that has 
 * already been deallocated, freed, or gone out of scope. 
 * Dereferencing a dangling pointer leads to undefined behavior, corrupted 
 * data, or runtime crashes (e.g., Segmentation Fault).
 *
 * COMMON CAUSES TRACKED IN THE LECTURE:
 * -------------------------------------
 * 1. Returning the address of a local variable from a function call.
 * 2. Pointing to a local variable inside an inner block that has exited.
 * 3. Deallocating dynamic heap memory manually (via free()) without resetting the pointer.
 */

/* =========================================================================
 * 1. LECTURE PROBLEM 1: RETURNING ADDRESS OF LOCAL VARIABLE
 * =========================================================================
 * Address allocation assumptions from the board trace:
 * Variable 'a' (main)  = Address 1000
 * Variable 'ptr' (main)= Address 2000
 * Variable 'b' (fun)   = Address 1500
 */

#include <stdio.h>

int *fun(void) {
    int b = 700; // Allocated on fun's stack frame (Address 1500)
    return &b;   // Returns 1500
}                // fun's stack frame pops off! Memory at 1500 is now unallocated.

void main_example_1() {
    int a = 600;     // Stored at Address 1000
    int *ptr = NULL; // Stored at Address 2000

    printf("%p\n", (void*)&a); // OUTPUT: 1000

    ptr = fun(); // ptr now stores 1500. It is a DANGLING POINTER.
    
    /* CRITICAL GATE CONCEPT:
     * Attempting to access the content at Address 1500 after the stack frame 
     * is destroyed causes unstable behavior or a Segmentation Fault.
     */
    // printf("%d\n", *ptr); // RUNTIME ERROR: Segmentation Fault / Undefined Behavior
}


/* =========================================================================
 * 2. LECTURE PROBLEM 2: OUT OF SCOPE INNER BLOCK VARIABLE
 * =========================================================================
 * Address allocation assumptions from the board trace:
 * Variable 'a' (main)      = Address 1000
 * Variable 'ptr' (main)    = Address 2000
 * Variable 'b' (inner block)= Address 3000
 */

int main() {
    int a = 600;     // Allocated at Address 1000
    int *ptr = NULL; // Allocated at Address 2000

    printf("%p\n", (void*)&a); // OUTPUT: 1000

    { // --- START OF INNER BLOCK ---
        int b = 700; // Allocated on the stack frame block at Address 3000
        
        printf("%p\n", (void*)&b); // OUTPUT: 3000
        
        ptr = &b; // ptr stores Address 3000
        
        printf("%p\n", (void*)ptr); // OUTPUT: 3000
    } // --- END OF INNER BLOCK --- 
    // Variable 'b' goes out of scope and is destroyed. Address 3000 is deallocated!

    /* ptr still points to Address 3000 */
    printf("%p\n", (void*)ptr); // OUTPUT: 3000 (Valid address tracking, but memory is dead)

    /* CRITICAL TRACE:
     * Accessing content at (3000) here is unsafe because the stack window closed.
     * While compilers sometimes print 700 if the stack hasn't been overwritten yet,
     * logically for the GATE exam, ptr is a DANGLING POINTER here.
     */
    printf("%d\n", *ptr); // OUTPUT/BEHAVIOR: Undefined Behavior (Historically 700 or Seg Fault)

    return 0;
}


/* =========================================================================
 * BEST PRACTICE REMEDY: HOW TO FIX A DANGLING POINTER
 * =========================================================================
 * As soon as memory goes out of scope or is freed via free(), immediately 
 * reset the pointer to NULL to prevent accidental dereferencing.
 * 
 * Example:
 *     free(ptr);
 *     ptr = NULL;
 */

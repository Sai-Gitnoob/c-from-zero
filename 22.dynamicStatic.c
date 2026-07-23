/* =========================================================================
 * TOPIC: STATIC (LEXICAL) SCOPING VS. DYNAMIC SCOPING
 * Source: Gate Smashers (GATE Compiler Design / PL Concepts)
 * =========================================================================
 * 
 * CONCEPT DEFINITIONS:
 * --------------------
 * 1. Static Scoping (Lexical): The scope of a variable is determined at 
 *    COMPILE TIME by its physical position in the source code text. A free 
 *    variable looks for its definition in its parent static block (outer block).
 * 
 * 2. Dynamic Scoping: The scope of a variable is determined at RUN TIME 
 *    based on the calling sequence (execution stack). A free variable looks 
 *    for its definition in the most recently called active function block.
 */

/* =========================================================================
 * PSEUDO-CODE REPRESENTATION OF THE BOARD PROBLEM
 * ========================================================================= */

// --- GLOBAL SCOPE ---
int x_global, y_global; 

void P(int n) {
    /* 'x' is a free variable here (not declared inside P).
     * Where does 'x' point?
     * - Static Scoping: Resolves to 'x_global' (where P is textually defined).
     * - Dynamic Scoping: Resolves to 'x_local_Q' (since Q called P).
     */
    x_global = (n + 2) / (n - 3); 
}

void Q() {
    // --- LOCAL SCOPE OF Q ---
    int x_local_Q, y_local_Q; 
    
    x_local_Q = 3;
    y_local_Q = 4;
    
    P(y_local_Q);      // Passes 4 as parameter 'n' to function P
    
    print(x_local_Q);         // --- STATEMENT (1)
}

void main() {
    x_global = 7;
    y_global = 8;
    
    Q();
    
    printf("d%",x_global);         // --- STATEMENT (2)
}

/* =========================================================================
 * GATE TRACE AND SOLUTIONS
 * =========================================================================
 *
 * CASE 1: VARIABLES ARE STATICALLY SCOPED (Default in C)
 * -------------------------------------------------------------------------
 * 1. Execution starts in main(): 
 *    - x_global = 7, y_global = 8
 * 2. main() calls Q():
 *    - Q allocates local variables: x_local_Q = 3, y_local_Q = 4
 * 3. Q() calls P(4):
 *    - Inside P(), n = 4. 
 *    - Target evaluation: (4 + 2) / (4 - 3) = 6 / 1 = 6
 *    - Static binding binds 'x' to global memory -> x_global becomes 6.
 *    - x_local_Q remains completely untouched (3).
 * 4. P() returns control back to Q():
 *    - Statement (1) prints the local variable 'x' of Q.
 *    - RESULT (1) = 3
 * 5. Q() finishes, destroying its stack frame. Control returns to main():
 *    - Statement (2) prints global 'x'.
 *    - RESULT (2) = 6
 *
 * OUTPUT (Static Scoping) -> (1): 3,  (2): 6
 * =========================================================================
 *
 * CASE 2: VARIABLES ARE DYNAMICALLY SCOPED
 * -------------------------------------------------------------------------
 * 1. Execution starts in main(): 
 *    - x_global = 7, y_global = 8
 * 2. main() calls Q():
 *    - Q allocates local variables: x_local_Q = 3, y_local_Q = 4
 * 3. Q() calls P(4):
 *    - Inside P(), n = 4.
 *    - Target evaluation: (4 + 2) / (4 - 3) = 6
 *    - Dynamic binding looks down the call stack: [main -> Q -> P]
 *    - The most recent active frame with variable 'x' is Q().
 *    - Therefore, 'x' binds to Q's local variable -> x_local_Q becomes 6.
 *    - x_global remains completely untouched (7).
 * 4. P() returns control back to Q():
 *    - Statement (1) prints the local variable 'x' of Q.
 *    - RESULT (1) = 6
 * 5. Q() finishes, destroying its stack frame. Control returns to main():
 *    - Statement (2) prints global 'x'.
 *    - RESULT (2) = 7
 *
 * OUTPUT (Dynamic Scoping) -> (1): 6,  (2): 7
 * ========================================================================= */

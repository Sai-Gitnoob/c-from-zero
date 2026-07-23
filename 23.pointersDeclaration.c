/* =========================================================================
 * TOPIC: COMPLEX DECLARATIONS IN C (The Right-Left Rule / Clockwise Rule)
 * Source: Gate Smashers (GATE Preparation Notes)
 * =========================================================================
 *
 * THE OPERATOR PRECEDENCE RULE FOR DECLARATIONS:
 * -----------------------------------------------
 * 1. Always start identifying from the variable name itself.
 * 2. Look to the right first (for array subscripts [] or function calls ()).
 * 3. Then look to the left (for pointer asterisks * ).
 * 4. Parentheses () alter the precedence order just like in math.
 */

/* =========================================================================
 * 1. STANDARD DECLARATION EXAMPLES
 * ========================================================================= */

// Example A: Array of 5 integers.
int a[5]; 

// Example B: 'p' is an array of 5 elements, where each element is a pointer to an int.
// Precedence: [] takes precedence over *.
int *p[5]; 

// Example C: 'p' is a pointer to an array of 10 integers.
// Precedence: Overridden by (). 'p' is firmly a pointer first.
int (*p)[10]; 

// Example D: 'a' is a pointer to a pointer to a character (Double pointer).
char **a; 


/* =========================================================================
 * 2. FUNCTION & FUNCTION POINTER DECLARATIONS
 * ========================================================================= */

// Example E: 'c' is a function that takes no arguments and returns a pointer to a char.
// Precedence: () takes precedence over *.
// char *c(); 

// Example F: 'c' is a pointer to a function that returns a plain char.
// Precedence: Overridden by (). 'c' is firmly a pointer first.
char (*c)(); 


/* =========================================================================
 * 3. ADVANCED GATE-LEVEL NESTED DECLARATIONS
 * ========================================================================= */

/* Example G: char (*(*c())[])()
 * Decoding path:
 * 1. Find identifier: 'c'
 * 2. Look right: 'c()' -> c is a function...
 * 3. Look left inside inner parens: '*c()' -> ...returning a pointer...
 * 4. Look right outside: '(*c())[]' -> ...to an array...
 * 5. Look left: '*(*c())[]' -> ...of pointers...
 * 6. Look right: '(*(*c())[])()' -> ...to functions...
 * 7. Look left: 'char' -> ...returning a character.
 * 
 * SUMMARY: c is a function which returns a pointer to an array of pointers 
 *          to functions which return character.
 */
char (*(*c())[])();


/* Example H: char (*(*c[5])())[6]   (Note: Board explicitly corrected 5 to 6 at the end)
 * Decoding path:
 * 1. Find identifier: 'c'
 * 2. Look right: 'c[5]' -> c is an array of 5 elements...
 * 3. Look left inside inner parens: '*c[5]' -> ...which are pointers...
 * 4. Look right outside: '(*c[5])()' -> ...to functions...
 * 5. Look left: '*(*c[5])()' -> ...returning pointers...
 * 6. Look right: '(*(*c[5])())[6]' -> ...to an array of 6...
 * 7. Look left: 'char' -> ...characters.
 * 
 * SUMMARY: c is an array of 5 elements which are pointers to functions 
 *          returning pointers to an array of 6 characters.
 */
char (*(*c[5])())[6];

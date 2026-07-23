/*
======================================================================
                         STORAGE CLASSES IN C
======================================================================

                   +-------------------+

                   |  Storage Classes  |
                   +---------+---------+
                             |
         +-------------+-----+------------+-------------+

         |             |                  |             |
     v   v             v                  v             v
       Auto         Register            Static        Extern
         |
         +---> Attributes:
               - Datatype
               - Storage class
               - Memory
               - Scope
               - Lifetime

======================================================================
                         CODE EXAMPLE (SCOPE)
======================================================================

main() 
{
    int a; // Scope of 'a' starts here
    {
        int b; // Scope of 'b' starts here
        {
            int c; // Scope of 'c' starts here
        } // 'c' goes out of scope here
    } // 'b' goes out of scope here
} // 'a' goes out of scope here

======================================================================
*/

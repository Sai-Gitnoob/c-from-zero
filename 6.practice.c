#include <stdio.h>

int main(void) {
    int m = 10;
    int n, n1;

    n = ++m;    // m becomes 11, n becomes 11
    n1 = m++;   // n1 becomes 11, m becomes 12
    n--;        // n becomes 10
    --n1;       // n1 becomes 10
    n -= n1;    // n = 10 - 10 = 0

    printf("%d\n", n); // Outputs: 0

    return 0;
}

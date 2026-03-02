#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {
    printf("SumLoop(10) = %ld\n", SumLoop(10));
    printf("SumRecur(10) = %ld\n", SumRecur(10));

    int large = 1000000; 
    printf("\nTesting large n = %d\n", large);
    printf("SumLoop(%d) = %ld\n", large, SumLoop(large));
    printf("SumRecur(%d) = %ld\n", large, SumRecur(large)); 

    return 0;
}

long SumLoop(int n) {
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

long SumRecur(int n) {
    if (n <= 0)
        return 0;
    else
        return n + SumRecur(n - 1);
}
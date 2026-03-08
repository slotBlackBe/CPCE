#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    if (i == n) 
        return 0;

    int value1 = 0, value2 = 0;

    if (w[i] <= wx) {
        x[i] = 1;
        value1 = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x);
    }

    x[i] = 0;
    value2 = KnapsackBT(w, v, n, wx, i + 1, x);

    if (value1 > value2) {
        x[i] = 1;
        return value1;
    } else {
        x[i] = 0;
        return value2;
    }
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int x[5];
    int vx;

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}
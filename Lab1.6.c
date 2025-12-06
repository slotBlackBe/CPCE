#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col) {
    scanf("%d", row);
    scanf("%d", col);
    int *arr = (int *)malloc((*row) * (*col) * sizeof(int));
    for (int i = 0; i < (*row) * (*col); i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);

    printf("--- MATRIX ELEMENTS ---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    free(data);
    return 0;
}

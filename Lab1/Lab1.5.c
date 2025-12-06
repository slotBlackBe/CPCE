#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col) {
    scanf("%d", row);
    scanf("%d", col);
    *value = (int *)malloc((*row) * (*col) * sizeof(int));
    for (int i = 0; i < (*row) * (*col); i++) {
        scanf("%d", &(*value)[i]);
    }
}

int main() {
    int *data, m, n;
    GetMatrix(&data, &m, &n);

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

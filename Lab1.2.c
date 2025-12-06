#include <stdio.h>
#include <stdlib.h>

void GetSet(int **array, int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);

    *array = (int *)malloc(*size * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &(*array)[i]);
    }
}

int main() {
    int *data;
    int num;

    GetSet(&data, &num);

    printf("\n--- SET ELEMENTS ---\n");
    for (int i = 0; i < num; i++) {
        printf("[%d] %d\n", i + 1, data[i]);
    }

    free(data);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *size) {
    scanf("%d", size);
    int *arr = (int *)malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int *data, num;
    data = GetSet(&num);

    for (int i = 0; i < num; i++) {
        printf("[%d] %d\n", i + 1, data[i]);
    }

    free(data);
    return 0;
}

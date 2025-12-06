#include <stdio.h>

int GetSet(int data[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    return n;
}

int main() {
    int data[100];
    int num;

    num = GetSet(data);

    printf("--- SET ELEMENTS ---\n");
    for (int i = 0; i < num; i++) {
        printf("[%d] %d\n", i + 1, data[i]);
    }

    return 0;
}
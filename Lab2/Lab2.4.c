#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][20], int *count) {
    int i = 0, j = 0, k = 0;
    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            str2[k][j] = '\0';
            k++;
            j = 0;
        } else {
            str2[k][j++] = str1[i];
        }
        i++;
    }
    str2[k][j] = '\0';
    *count = k + 1;
}

int main() {
    char out[20][20];
    int num;
    explode("I/Love/You", '/', out, &num);

    printf("--- EXPLODED STRINGS ---\n");
    for (int i = 0; i < num; i++) {
        printf("[%d] %s\n", i, out[i]);
    }
    return 0;
}

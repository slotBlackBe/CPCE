#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char str1[]) {
    int len = strlen(str1);
    char *str2 = (char *)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';
    return str2;
}

int main() {
    char text[50];
    char *out;
    gets(text);
    out = reverse(text);
    printf("%s\n", out);
    free(out);
    return 0;
}

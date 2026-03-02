#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6;
    int find = 5;

    int pos = BinSearch(data, n, find);

    if (pos != -1)
        printf("Found %d at %d\n", find, pos);
    else
        printf("Not found\n");

    return 0;
}

int BinSearch(int data[], int n, int find) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (data[mid] == find)
            return mid + 1;

        else if (find < data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
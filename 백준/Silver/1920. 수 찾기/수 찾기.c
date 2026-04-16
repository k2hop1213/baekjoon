#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)return 1;
    else if (*(int*)a > *(int*)b)return -1;
    return 0;
}
int binary_search(int num, int list[], int key) {
    int low, high, middle;
    low = 0;
    high = num - 1;
    while (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle]) return 1;
        else if (key > list[middle]) low = middle + 1;
        else high = middle - 1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    qsort(arr, n, sizeof(int), compare);
    int* arr1 = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
        if (binary_search(n, arr, arr1[i]) == 1) {
            printf("1\n");
        }
        else printf("0\n");

    }

    free(arr);
    free(arr1);

    return 0;
}
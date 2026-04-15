#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    int* arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);


    int cnt = (int)(0.15 * n + 0.5);


    int sum = 0;
    for (int i = cnt; i < n - cnt; i++) {
        sum += arr[i];
    }

    int avg = (int)((double)sum / (n - 2 * cnt) + 0.5);

    printf("%d\n", avg);

    free(arr);

    return 0;
}
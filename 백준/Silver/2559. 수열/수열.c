#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = malloc(sizeof(int) * n);
    int* sum = calloc(sizeof(int), (n - m + 1));
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for (int i = 0; i < m; i++) {
        sum[0] += arr[i];
    }
    for (int i = 1; i < n - m + 1; i++) {
        sum[i] += (sum[i - 1] - arr[i - 1] + arr[i + m - 1]);
    }
    int max = sum[0];

    for (int i = 0; i < n - m + 1; i++) {
        if (max < sum[i]) {
            max = sum[i];
        }
    }

    printf("%d", max);

    return 0;
}
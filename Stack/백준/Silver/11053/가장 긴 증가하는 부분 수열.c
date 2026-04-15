#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

    int* len = calloc(sizeof(int), n);
    for (int i = 0; i < n; i++) len[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        if (max_len < len[i]) {
            max_len = len[i];
        }
    }

    printf("%d", max_len);
    return 0;
}

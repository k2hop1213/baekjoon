#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** arr = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        arr[i] = (int*)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < 2; k++) {
            scanf("%d", &arr[i][k]);
        }
    }
    int* cnt = calloc(sizeof(int), n);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < 2; k++) {
            if (arr[i][k] == 1) {
                int temp = (k == 0) ? arr[i][1] : arr[i][0];
                cnt[temp - 1]++;
                for (int j = 0; j < m; j++) {
                    if (j != i) {
                        if (temp == arr[j][0] || temp == arr[j][1]) {
                            int temptemp = (temp == arr[j][1]) ? arr[j][0] : arr[j][1];
                            cnt[temptemp - 1]++;
                        }
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i])result++;
    }
    printf("%d", result);

    return 0;
}
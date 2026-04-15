#include <stdio.h>
#include <stdlib.h>

int cntsum(int num[], int n, int m) {
    int cnt = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += num[i];
            }
        }

        if (sum == m) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int N, S;
    scanf("%d %d", &N, &S);

    int* sequence = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }

    // 결과 출력
    int result = cntsum(sequence, N, S);
    printf("%d\n", result);

    return 0;
}
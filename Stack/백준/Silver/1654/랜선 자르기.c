#include <stdio.h>

long long cables[10001];

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    long long left = 1, right = 0;
    for (int i = 0; i < K; ++i) {
        scanf("%lld", &cables[i]);
        if (cables[i] > right) {
            right = cables[i];
        }
    }

    long long result = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int count = 0;

        for (int i = 0; i < K; ++i) {
            count += cables[i] / mid;
        }

        if (count >= N) {
            if (mid > result) {
                result = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}

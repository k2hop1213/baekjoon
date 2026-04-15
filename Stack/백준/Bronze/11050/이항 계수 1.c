#include <stdio.h>

long long binomialCoefficient(int N, int K) {
    long long dp[11][11] = {0};  // 최대 N, K 값이 10이므로 배열 크기를 11로 설정

    // 초기값 설정
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    // 이항 계수 계산
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[N][K];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    long long result = binomialCoefficient(N, K);

    printf("%lld\n", result);

    return 0;
}

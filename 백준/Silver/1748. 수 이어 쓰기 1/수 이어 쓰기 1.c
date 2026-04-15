#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long digits = 0; // 결과로 출력할 자릿수

    int len = 1; // 현재 범위의 자릿수
    long long start = 1; // 현재 범위의 시작 값
    long long end = 9; // 현재 범위의 끝 값

    while (start <= N) {
        if (N <= end) {
            digits += (N - start + 1) * len;
            break;
        }
        else {
            digits += (end - start + 1) * len;
            len++;
            start = end + 1;
            end = end * 10 + 9;
        }
    }

    printf("%lld", digits);

    return 0;
}

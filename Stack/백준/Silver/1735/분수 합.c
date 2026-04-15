#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplify_fraction(int *numerator, int *denominator) {
    int common_factor = gcd(*numerator, *denominator);
    *numerator /= common_factor;
    *denominator /= common_factor;
}

int main() {
    char input[100];
    int numerator1, denominator1, numerator2, denominator2;

    // 두 분수 입력 받기
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &numerator1, &denominator1);

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &numerator2, &denominator2);

    // 두 분수의 합 계산
    long long result_numerator = (long long)numerator1 * denominator2 + (long long)numerator2 * denominator1;
    long long result_denominator = (long long)denominator1 * denominator2;

    // 결과를 기약분수로 변환
    simplify_fraction((int*)&result_numerator, (int*)&result_denominator);

    // 결과 출력
    printf("%lld %lld\n", result_numerator, result_denominator);

    return 0;
}

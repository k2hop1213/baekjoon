#include <stdio.h>

// 올림 계산 함수
long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    // 입력값 선언
    long long N, S, M, L, XL, XXL, XXXL, T, P;

    // 입력값 받기
    scanf("%lld", &N);
    scanf("%lld %lld %lld %lld %lld %lld", &S, &M, &L, &XL, &XXL, &XXXL);
    scanf("%lld %lld", &T, &P);

    // 티셔츠 최소 묶음 계산
    long long tshirt_bundles = ceil_div(S, T) 
                             + ceil_div(M, T) 
                             + ceil_div(L, T) 
                             + ceil_div(XL, T) 
                             + ceil_div(XXL, T) 
                             + ceil_div(XXXL, T);

    // 펜 최대 묶음과 남은 펜 계산
    long long pen_bundles = N / P;
    long long single_pens = N % P;

    // 결과 출력
    printf("%lld\n", tshirt_bundles);
    printf("%lld %lld\n", pen_bundles, single_pens);

    return 0;
}

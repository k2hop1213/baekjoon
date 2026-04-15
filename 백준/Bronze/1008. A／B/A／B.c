#include <stdio.h>

int main() {
    int A, B;
    
    // 두 정수 A와 B를 입력 받음
    scanf("%d %d", &A, &B);
    
    // A/B를 계산하고 출력
    printf("%.9lf\n", (double)A / B);

    return 0;
}

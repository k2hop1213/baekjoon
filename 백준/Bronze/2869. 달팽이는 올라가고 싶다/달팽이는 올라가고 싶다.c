#include <stdio.h>

int main() {
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    // 달팽이가 정상에 도달하기 위한 날짜 계산
    int days = (V - B - 1) / (A - B) + 1;

    // 결과 출력
    printf("%d\n", days);

    return 0;
}

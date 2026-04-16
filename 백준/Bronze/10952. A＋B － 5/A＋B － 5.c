#include <stdio.h>

int main() {
    int A, B;

    // 입력이 0 0이 들어올 때까지 반복
    while (1) {
        // 두 정수 A와 B를 입력받음
        scanf("%d %d", &A, &B);

        // 입력이 0 0이면 반복을 종료
        if (A == 0 && B == 0) {
            break;
        }

        // 각 테스트 케이스에 대해 A+B 출력
        printf("%d\n", A + B);
    }

    return 0;
}

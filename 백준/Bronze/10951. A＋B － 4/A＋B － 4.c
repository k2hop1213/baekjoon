#include <stdio.h>

int main() {
    int A, B;

    // 입력이 끝날 때까지 계속 입력을 받음
    while (scanf("%d %d", &A, &B) != EOF) {
        // 각 테스트 케이스에 대해 A+B 출력
        printf("%d\n", A + B);
    }

    return 0;
}

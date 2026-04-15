#include <stdio.h>

int main() {
    int T;  // 테스트 케이스의 개수
    int A, B;  // 두 정수 A와 B

    // 테스트 케이스의 개수 입력
    scanf("%d", &T);

    // 각 테스트 케이스에 대해 A+B 출력
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}

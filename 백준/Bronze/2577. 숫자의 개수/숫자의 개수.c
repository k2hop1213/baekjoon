#include <stdio.h>

int main() {
    int A, B, C;
    int result;
    int count[10] = {0};  // 0부터 9까지의 숫자가 몇 번 나왔는지를 저장할 배열

    // A, B, C 입력
    scanf("%d %d %d", &A, &B, &C);

    // A × B × C 계산
    result = A * B * C;

    // 각 자리 숫자의 개수 세기
    while (result > 0) {
        count[result % 10]++;
        result /= 10;
    }

    // 결과 출력
    for (int i = 0; i < 10; i++) {
        printf("%d\n", count[i]);
    }

    return 0;
}

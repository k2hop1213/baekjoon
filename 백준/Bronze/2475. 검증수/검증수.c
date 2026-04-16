#include <stdio.h>

int main() {
    int numbers[5];

    // 고유번호의 처음 5자리를 입력 받음
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }

    // 검증수 계산
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i] * numbers[i];
    }
    int verificationNumber = sum % 10;

    // 검증수 출력
    printf("%d\n", verificationNumber);

    return 0;
}

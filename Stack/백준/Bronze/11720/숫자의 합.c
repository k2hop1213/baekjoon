#include <stdio.h>

int main() {
    int N;
    
    // 숫자의 개수 N 입력
    scanf("%d", &N);

    char digit;
    int sum = 0;

    // N개의 숫자 입력 및 합 계산
    for (int i = 0; i < N; i++) {
        scanf(" %c", &digit);  // 숫자 하나씩 입력 (공백 없이)
        sum += digit - '0';     // ASCII 코드를 이용하여 숫자로 변환 후 합산
    }

    // 합 출력
    printf("%d\n", sum);

    return 0;
}

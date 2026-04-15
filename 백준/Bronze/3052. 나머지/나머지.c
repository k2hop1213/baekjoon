#include <stdio.h>

int main() {
    int num;
    int remainder[42] = {0};  // 42로 나눈 나머지의 개수를 저장할 배열
    int count = 0;  // 서로 다른 나머지의 개수

    // 10개의 수 입력받기
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        remainder[num % 42] = 1;  // 나머지를 인덱스로 사용하여 해당 나머지가 나온 횟수를 저장
    }

    // 배열을 순회하며 나머지가 나온 횟수가 1 이상인 경우 count 증가
    for (int i = 0; i < 42; i++) {
        if (remainder[i] > 0) {
            count++;
        }
    }

    // 서로 다른 나머지의 개수 출력
    printf("%d\n", count);

    return 0;
}

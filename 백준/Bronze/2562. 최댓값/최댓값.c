#include <stdio.h>

int main() {
    int numbers[9];
    int max = 0;
    int index = 0;

    // 9개의 자연수 입력
    for (int i = 0; i < 9; i++) {
        scanf("%d", &numbers[i]);

        // 최댓값과 위치 갱신
        if (numbers[i] > max) {
            max = numbers[i];
            index = i + 1;  // 위치는 1부터 시작하므로 i에 1을 더함
        }
    }

    // 최댓값 출력
    printf("%d\n", max);
    // 최댓값의 위치 출력
    printf("%d\n", index);

    return 0;
}

#include <stdio.h>

int main() {
    int N;
    
    // 정수의 개수 N 입력
    scanf("%d", &N);

    int num;
    int min = 1000001;  // 초기 최솟값 설정
    int max = -1000001; // 초기 최댓값 설정

    // N개의 정수 입력 및 최솟값, 최댓값 찾기
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    // 최솟값과 최댓값 출력
    printf("%d %d\n", min, max);

    return 0;
}

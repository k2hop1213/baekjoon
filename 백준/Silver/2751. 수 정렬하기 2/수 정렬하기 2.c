#include <stdio.h>
#include <stdlib.h>

// 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    // 수를 저장할 배열 동적 할당
    int *numbers = (int *)malloc(N * sizeof(int));

    // 수 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    // 오름차순 정렬
    qsort(numbers, N, sizeof(int), compare);

    // 정렬된 수 출력
    for (int i = 0; i < N; i++) {
        printf("%d\n", numbers[i]);
    }

    // 동적 할당된 메모리 해제
    free(numbers);

    return 0;
}

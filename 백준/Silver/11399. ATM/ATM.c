#include <stdio.h>
#include <stdlib.h>

// 비교 함수: 오름차순 정렬
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int P[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }

    // 시간을 오름차순으로 정렬
    qsort(P, N, sizeof(int), compare);

    int total_time = 0;
    int cumulative_time = 0;

    // 최소 대기 시간 계산
    for (int i = 0; i < N; i++) {
        cumulative_time += P[i];  // 현재 사람까지 걸리는 시간
        total_time += cumulative_time; // 총 대기 시간에 추가
    }

    printf("%d\n", total_time);
    return 0;
}
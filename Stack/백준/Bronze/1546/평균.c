#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // 동적으로 배열 할당
    int *scores = (int *)malloc(N * sizeof(int));
    int max_score = 0;

    // 입력 받으면서 최댓값 찾기
    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    double sum = 0;

    // 모든 점수를 점수/M*100으로 고쳐서 합 구하기
    for (int i = 0; i < N; i++) {
        sum += (double)scores[i] / max_score * 100;
    }

    // 평균 출력
    printf("%.6lf\n", sum / N);

    // 동적으로 할당한 메모리 해제
    free(scores);

    return 0;
}

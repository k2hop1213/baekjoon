#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findClosestSum(int cards[], int n, int m) {
    int closestSum = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int currentSum = cards[i] + cards[j] + cards[k];
                if (currentSum <= m && currentSum > closestSum) {
                    closestSum = currentSum;
                }
            }
        }
    }

    return closestSum;
}

int main() {
    int n, m;

    // 입력 받기
    scanf("%d %d", &n, &m);

    // 카드 배열 동적 할당 및 입력 받기
    int *cards = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 카드 배열 정렬
    qsort(cards, n, sizeof(int), compare);

    // 가장 가까운 합 찾기
    int result = findClosestSum(cards, n, m);

    // 결과 출력
    printf("%d\n", result);

    // 동적 할당 해제
    free(cards);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int count[20000001] = { 0 };
int main() {
    int n, m;

    // 상근이가 가지고 있는 숫자 카드의 개수 N 입력
    scanf("%d", &n);

    // 숫자 카드에 적혀있는 정수 배열 cards 입력
    int* cards = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 몇 개의 숫자 카드를 구해야 하는지 M 입력
    scanf("%d", &m);

    // 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수 배열 numbers 입력
    int* numbers = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &numbers[i]);
    }

    
    for (int i = 0; i < n; i++) {
        count[cards[i] + 10000000]++;  // 음수를 배열 인덱스로 사용하지 않기 위해 10,000,000을 더해줌
    }

    // 각 숫자 카드의 개수 출력
    for (int i = 0; i < m; i++) {
        printf("%d ", count[numbers[i] + 10000000]);
    }

    return 0;
}
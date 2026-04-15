#include <stdio.h>

int main() {
    int i, j, N, num, count[10001] = { 0, };
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        count[num]++;
    }
    for (i = 0; i < 10001; i++) {
        if (count[i] != 0) {
            for (j = 0; j < count[i]; j++) {
                printf("%d \n", i);
            }
        }
    }
    return 0;
}
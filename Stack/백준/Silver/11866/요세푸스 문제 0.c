#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int* arr = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) arr[i] = i + 1;
    int cnt = 0;
    int check = 0;
    int index = 0;

    printf("<");
    while (cnt < N) {
        index %= N;
        if (arr[index] != 0) {
            check++;
            if (check % K == 0) {
                printf("%d", arr[index]);
                cnt++;
                if (cnt < N) printf(", ");
                arr[index] = 0;
            }
        }
        index++;
    }
    printf(">\n");

    free(arr);


    return 0;
}
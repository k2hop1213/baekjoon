#include <stdio.h>
#include <stdlib.h>
int cnt(int n) {
    int* cnt_arr = malloc(sizeof(int) * (n + 1));
    cnt_arr[1] = 1;
    cnt_arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        cnt_arr[i] = cnt_arr[i - 1] + cnt_arr[i - 2];
        cnt_arr[i] %= 15746;
    }

    return cnt_arr[n];
}
int main() {
    // 1 , 00 11 , 100 001 111, 0011 0000 1001 1100 1111, 10000 00100 00001 11100 11001 10011 11111 00000
    int N;
    scanf("%d", &N);
    printf("%d", cnt(N));




    return 0;
}
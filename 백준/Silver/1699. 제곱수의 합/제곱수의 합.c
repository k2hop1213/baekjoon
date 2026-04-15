#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int cnt[100001]; 

    for (int i = 1; i <= N; i++) {
        cnt[i] = i;
        for (int j = 1; j * j <= i; j++) {
            cnt[i] = (cnt[i] < cnt[i - j * j] + 1) ? cnt[i] : cnt[i - j * j] + 1;
        }
    }

    printf("%d\n", cnt[N]);

    return 0;
}
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    long long sum = 0;
    long long partialSum = 0;

    for (int i = 0; i < N; i++) {
        partialSum += arr[i];
    }

    for (int i = 0; i < N; i++) {
        partialSum -= arr[i];
        sum += partialSum * arr[i];
    }

    printf("%lld\n", sum);

    return 0;
}

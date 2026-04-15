#include <stdio.h>
int isPrime(int num) {
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return 0;
        }
    }
    return 1;
}
int main() {

    int n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        for (int k = 2; k <= arr[i] / 2; k++) {
            if (isPrime(k) && isPrime(arr[i] - k)) {
                a = k;
                b = arr[i] - k;
            }
        }
        printf("%d %d\n", a, b);
    }


    return 0;
}

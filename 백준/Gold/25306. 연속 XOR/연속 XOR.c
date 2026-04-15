#include <stdio.h>

long long xor(long long x) {
    if (x % 4 == 0) {
        return x;
    }
    else if (x % 4 == 1) {
        return 1;
    }
    else if (x % 4 == 2) {
        return x + 1;
    }
    else { 
        return 0;
    }
}

int main() {
    long long A, B;

    scanf("%lld %lld", &A, &B);

    long long result = xor(A - 1) ^ xor(B);
    printf("%lld\n", result);

    return 0;
}
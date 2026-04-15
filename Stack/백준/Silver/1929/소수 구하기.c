#include <stdio.h>
#include <stdbool.h>

void printPrimes(int m, int n) {
    // 에라토스테네스의 체를 이용하여 소수를 찾는 함수
    bool isPrime[n+1];
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 결과 출력
    for (int i = m; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int m, n;
    
    // 입력 받기
    scanf("%d %d", &m, &n);

    // 함수 호출
    printPrimes(m, n);

    return 0;
}

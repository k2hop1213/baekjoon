#include <stdio.h>

// 함수 선언
int isPalindrome(int num);
int isPrime(int num);

int main() {
    // 입력 받기
    int N;
    scanf("%d", &N);

    // N보다 크거나 같은 소수이면서 팰린드롬인 수 찾기
    while (1) {
        if (isPrime(N) && isPalindrome(N)) {
            printf("%d\n", N);
            break;
        }
        N++;
    }

    return 0;
}

// 숫자가 팰린드롬인지 확인하는 함수
int isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

// 소수인지 확인하는 함수
int isPrime(int num) {
    if (num < 2) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

#include <stdio.h>
#include <stdlib.h>

int sumEachDigit(int a) {
    int sum = a;  // 자기 자신도 더해야 함
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main() {
    int arr[10001] = {0};

    for (int i = 1; i <= 10000; i++) {
        int idx = sumEachDigit(i);
        if (idx <= 10000) {  
            arr[idx] = 1;  
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i] == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
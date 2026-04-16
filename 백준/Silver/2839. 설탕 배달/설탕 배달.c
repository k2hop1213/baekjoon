#include <stdio.h>

int sugar(int num) {
    if (num % 5 == 0) {

        return num / 5;
    }
    else {

        int num5 = num / 5; // 18이면 3
        for (int i = num5; i >= 0; i--) {
            int temp = num - i * 5; // 18 - 15 10 5 0
            if (temp % 3 == 0) { 
                return i + temp / 3;
            }
        }

        return -1;
    }
}

int main() {
    int a;
    scanf("%d", &a);

    int result = sugar(a);
    printf("%d", result);

    return 0;
}
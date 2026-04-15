#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;
    int number = 666;

    while (1) {
        int temp = number;
        while (temp >= 666) {
            if (temp % 1000 == 666) {
                count++;
                break;
            }
            temp /= 10;
        }
        if (count == N) {
            printf("%d\n", number);
            break;
        }
        number++;
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

void cantor(int n, int start, int end) {
    if (n == 0) {
        for (int i = start; i < end; i++) {
            printf("-");
        }
        return;
    }

    int length = end - start;
    int temp = length / 3;

    cantor(n - 1, start, start + temp);
    for (int i = 0; i < temp; i++) {
        printf(" ");
    }
    cantor(n - 1, end - temp, end);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int length = (int)pow(3, n);
        cantor(n, 0, length);
        printf("\n");
    }

    return 0;
}
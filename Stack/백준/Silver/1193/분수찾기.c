#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int n = 1;
    int sum = 0;

    while (1) {
        sum += n;
        if (sum >= X)
            break;
        n++;
    }

    int diff = sum - X;

    if (n % 2 == 0)
        printf("%d/%d\n", n - diff, 1 + diff);
    else
        printf("%d/%d\n", 1 + diff, n - diff);

    return 0;
}
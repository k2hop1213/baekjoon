#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);

        int distance = y - x;
        int cnt = 0;
        int sum = 0;

        while (distance > 0) {
            cnt++;
            distance -= cnt / 2;
        }

        printf("%d\n", cnt - 1);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int a, b, c;

    while (1) {
        int num[3] = { 0 };
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        num[0] = a;
        num[1] = b;
        num[2] = c;
        for (int i = 0; i < 2; i++) {
            for (int k = i + 1; k < 3; k++) {
                if (num[i] > num[k]) {
                    int temp = num[i];
                    num[i] = num[k];
                    num[k] = temp;
                }
            }
        }
        if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) {
            printf("right\n");
        }
        else printf("wrong\n");

    }

	return 0;
}
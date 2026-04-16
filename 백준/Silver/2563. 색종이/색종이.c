#include <stdio.h>
int main() {
    int paper[100][100] = {0};
    int n;
    scanf("%d", &n);
    int x, y;
    while (n--) {
        
        scanf("%d %d", &x, &y);
        for (int i = x; i < x + 10; i++) {
            for (int k = y; k < y + 10; k++) {
                if (paper[k][i])continue;
                paper[k][i] = 1;
            }
        }
        

    }

    int sum = 0;
    for (int i = 0; i < 100; i++) {
        for (int k = 0; k < 100; k++) {
            if (paper[k][i])sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
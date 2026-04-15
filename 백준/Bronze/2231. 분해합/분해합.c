#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int result = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
            
        }
        if (i + sum == n) {
                result = i;
                break;
        }

    }
    printf("%d", result);

    return 0;
}
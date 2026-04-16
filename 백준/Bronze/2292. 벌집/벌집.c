#include <stdio.h>
int main() {
    // 1 7 19 37 61 공차가 등차수열 6 12 18 ...

    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    int start = 1;
    int end = 1;
    int gongchar = 0;
    int result = 1;
    while (1) {
        start = end;
        gongchar = 6 * result;
        end += gongchar;
        if (start <= n && n <= end) {
            result++;
            break;
        }
        result++;
        
    }
    printf("%d", result);
    return 0;
}
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char N[1000001], M[1000001];
        scanf("%s %s", N, M);
        int a = 0;
        int b = 0;
        for (int i = 0; i < strlen(N); i++) {
            if (N[i] == M[i]) continue;
            if (N[i] == '1')a++;
            else b++;
        }
        int result = 0;
        if (a > b)result = b + (a - b);
        else if (a < b)result = a + (b - a);
        else result = b;
        printf("%d\n", result);
    }

    return 0;
}
#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    int k, n;
    
    while (T--) {
        
        scanf("%d\n%d", &k, &n);
        int** sum = malloc(sizeof(int*) * (k + 1));
        for (int i = 0; i < k + 1; i++) sum[i] = calloc(sizeof(int),n + 1);
        for (int i = 1; i < n + 1; i++)sum[0][i] = i;//0층에 사는 사람들 수
        for (int i = 1; i < k + 1; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j];
            }
        }
        printf("%d\n", sum[k][n]);
    }



    return 0;
}
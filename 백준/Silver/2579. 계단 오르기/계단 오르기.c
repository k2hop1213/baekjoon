#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);
    int* memo = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    memo[1] = arr[0];
    if (n == 1) {
        printf("%d", memo[1]);
        return 0;
    }
    memo[2] = arr[0] + arr[1];
    if (n == 2) {
        printf("%d", memo[2]);
        return 0;
    }
    memo[3] = arr[0] + arr[2] > arr[1] + arr[2] ? arr[0] + arr[2] : arr[1] + arr[2];
    if (n == 3) {
        printf("%d", memo[3]);
        
        return 0;
    }
    
    for (int i = 4; i < n + 1; i++) {

        memo[i] = arr[i - 1] + ((memo[i - 2] > memo[i - 3] + arr[i - 2]) ? memo[i - 2] : memo[i - 3] + arr[i - 2]);
    }

    
    printf("%d\n", memo[n]);
    
    
    free(arr);
    free(memo);

    return 0;
}
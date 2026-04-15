#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);
        if (i != 0) {
            arr[i] += arr[i - 1];
        }
    }
    
    int m;
    scanf("%d", &m);
    int a, b;
    while (m--) {
        scanf("%d %d", &a, &b);
        int result = 0;
        result = arr[b - 1];
        if (a > 1 && a!=b) {
            result -= arr[a - 2];
        }
        else if (a == b) {
            result -= arr[b - 2];
        }
        printf("%d\n", result);
    }

    

    return 0;
}
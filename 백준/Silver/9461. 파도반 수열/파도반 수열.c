#include <stdio.h>
#include <stdlib.h>
long long len(int a) {
    if (a <= 3)return 1;
    long long* arr = calloc(a + 1, sizeof(long long));
    
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i < a + 1; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    return arr[a];
}
int main() {
    int n;
    scanf("%d", &n);
    int a;
    while (n--) {
        scanf("%d", &a);
        long long result = len(a);
        printf("%lld\n", result);
    }



    return 0;
}
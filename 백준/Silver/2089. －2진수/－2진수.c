#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

 
    char arr[65];  
    int idx = 0;

    while (n != 0) {
        long long r = n % -2;
        n /= -2;

 
        if (r < 0) {
            r += 2;
            n += 1;
        }

        arr[idx++] = r + '0'; 
    }

    
    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }

    return 0;
}
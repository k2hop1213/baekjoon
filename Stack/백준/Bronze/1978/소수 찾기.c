#include <stdio.h>
isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int a;
    int cnt = 0;
    while (n--) {
        scanf("%d", &a);
        if (isPrime(a))cnt++;
    
    }
    printf("%d", cnt);


	return 0;
}
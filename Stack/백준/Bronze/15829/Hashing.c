#include <stdio.h>
#include <string.h>
int main() {
    unsigned long long r = 31;
    unsigned long long M = 1234567891;
    int n;
    scanf("%d", &n);
    char* arr = malloc(sizeof(char) * (n + 1));
    scanf("%s", arr);
    unsigned long long sum = 0;
    unsigned long long temp = 1;
    for (int i = 0; i < strlen(arr); i++) {
        sum = (sum + (arr[i] - 'a' + 1) * temp) % M;
        temp *= r;
        temp %= M;
    }
    printf("%llu", sum % M);

    return 0;
}
#include <stdio.h>
int main() {
    long long s;
    scanf("%lld", &s);
    long long cnt = 1;
    long long  n = 0;
    
    while (n < s) {
        n += cnt;
        cnt++;
    }
    cnt--;
    if (n == s) printf("%lld", cnt);
    else printf("%lld", cnt - 1);
    return 0;
}
#include <stdio.h>
long long cnt(long long n) {
    long long cnt_arr[91] = { 0 };
    cnt_arr[1] = 1;
    cnt_arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt_arr[i] = cnt_arr[i - 1] + cnt_arr[i - 2];
    }
    return cnt_arr[n];
    // 1000 1010 1001 , 10000 10100 10010 10001 10101 , 100000 101000 100100 100010 100001 101010 101001 100101 
}
int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", cnt(n));



    return 0;
}
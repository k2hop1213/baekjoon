#include <stdio.h>
int cnt(int n) {
    int cnt_arr[10001] = { 0 }; // 1 2 3  5 8 
    cnt_arr[1] = 1;
    cnt_arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        cnt_arr[i] = cnt_arr[i - 1] + cnt_arr[i - 2];
        cnt_arr[i] %= 10007;
    }
    return cnt_arr[n];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", cnt(n));



    return 0;
}
#include <stdio.h>
int isHansu(int n) {
    int index = 0;
    int arr[4] = { 0 };

    while (n > 0) {
        arr[index++] = n % 10;
        n /= 10;
    }
    int prev = arr[1] - arr[0];
    for (int i = 0; i < index - 1; i++) {
        int gongcha = arr[i + 1] - arr[i];
        if (prev != gongcha) {
            return 0;
        }
        prev = gongcha;
    }
    return 1;
}
int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (isHansu(i))cnt++;
    }
    printf("%d", cnt);


    return 0;
}
#include <stdio.h>
int cnt_num(int num) {
    int cnt_arr[11] = { 0 };

    cnt_arr[1] = 1;
    cnt_arr[2] = 2;
    cnt_arr[3] = 4;
    for (int i = 4; i < 11; i++) {
        
        cnt_arr[i] += cnt_arr[i - 1] + cnt_arr[i - 2] + cnt_arr[i - 3];
        
    }

    return cnt_arr[num];
}
int main() {

    int a;
    scanf("%d", &a);
    int num = 0;
    for (int i = 0; i < a; i++) {
        scanf("%d", &num);
        printf("%d\n", cnt_num(num));

    }


    return 0;
}
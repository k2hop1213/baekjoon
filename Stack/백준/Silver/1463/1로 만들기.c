#include <stdio.h>
#include <stdlib.h>
int calculate_cnt(int num) {

    int* cnt_arr = malloc(sizeof(int) * (num + 1));
    
        
    cnt_arr[1] = 0;
    for (int i = 2; i <= num; i++) {
        cnt_arr[i] = cnt_arr[i - 1] + 1; // i = 2 좌변에 1이 들어감 , i = 3 일때 2가 되는데 조건문에 걸려서  cnt_arr[3] = 1 이됨
        // cnt_arr[i]는 i 가 1이 되기위한 최소 연산 횟수
        if (i % 2 == 0) {
            cnt_arr[i] = (cnt_arr[i] < cnt_arr[i / 2] + 1) ? cnt_arr[i] : cnt_arr[i / 2] + 1;
        }

        if (i % 3 == 0) {
            cnt_arr[i] = (cnt_arr[i] < cnt_arr[i / 3] + 1) ? cnt_arr[i] : cnt_arr[i / 3] + 1;
        }
    }

    
    return cnt_arr[num];
}
int main() {

    int a;
    scanf("%d", &a);
    int result = calculate_cnt(a);
    printf("%d", result);

    return 0;
}
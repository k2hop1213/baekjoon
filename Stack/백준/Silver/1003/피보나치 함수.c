#include <stdio.h>
struct fibo_cnt {
    int cnt;
    int cnt1;
};
struct fibo_cnt result[41];
struct fibo_cnt fibonacci(int n) {
    struct fibo_cnt result1;
    if (n == 0) {
        result1.cnt = 1;
        result1.cnt1 = 0;

    }
    else if (n == 1) {
        result1.cnt = 0;
        result1.cnt1 = 1;

    }
    else {
        if (result[n].cnt != -1 && result[n].cnt1 != -1) {
            return result[n];
        }

        struct fibo_cnt fc1 = fibonacci(n - 1);
        struct fibo_cnt fc2 = fibonacci(n - 2);
        result1.cnt = fc1.cnt + fc2.cnt;
        result1.cnt1 = fc1.cnt1 + fc2.cnt1;


        result[n] = result1;
    }
    return result1;
}

int main() {
    int T;
    scanf("%d", &T);
    int num;
    while (T--) {
        
        scanf("%d", &num);
        memset(result, -1, sizeof(result));
        struct fibo_cnt b = fibonacci(num);
        printf("%d %d\n", b.cnt, b.cnt1);
    }

    return 0;
}
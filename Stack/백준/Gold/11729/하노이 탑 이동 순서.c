#include <stdio.h>
void hanoi(int n, int start, int work, int target) {

    if (n == 1) {
        printf("%c %c\n", start,target);
    }
    else {
        hanoi(n - 1, start, target, work);
        printf("%c %c\n", start,target);
        hanoi(n - 1, work, start, target);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    int b = (int)pow(2, a);
    b--;
    printf("%d\n", b);
    hanoi(a, '1', '2', '3');
    

    return 0;
}
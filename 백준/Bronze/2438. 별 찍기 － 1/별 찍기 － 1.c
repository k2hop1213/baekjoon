#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a = n;
    for (int i = 0; i < n; i++) {
        for (int k = a; k <= n; k++) {
            printf("*");
            
        }
        printf("\n");
        a--;
    }

	return 0;
}
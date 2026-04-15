#include <stdio.h>
#include <string.h>

int isVPS(char* str) {
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
            if (count < 0) {
                return 0; // ')'가 더 많이 나왔으면 VPS가 아님
            }
        }
    }

    return count == 0; // count가 0이면 VPS
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char str[51];
        scanf("%s", str);

        if (isVPS(str)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

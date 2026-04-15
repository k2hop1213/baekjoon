#include <stdio.h>
#include <string.h>
int main() {
    char str[6];
    while (1) {
        int flag = 0;
        scanf("%s", str);
        if (strcmp(str, "0") == 0) {
            break;
        }
        for (int i = 0; i < strlen(str) / 2; i++) {
            if (str[i] != str[strlen(str) - i - 1]) {
                flag = 1;
                break;
            }
        }
        if (flag)printf("no\n");
        else printf("yes\n");
    }



    return 0;
}
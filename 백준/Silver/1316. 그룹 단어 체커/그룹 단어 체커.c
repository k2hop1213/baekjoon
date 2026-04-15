#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n--) {
        int ap[26] = { 0 };
        char str[101];
        scanf("%s", str);
        int flag = 0;
        for (int i = 0; i < strlen(str); i++) {
            char temp = str[i];
            if (ap[str[i] - 'a'] && str[i - 1] != temp) {
                flag = 1;
            }
            ap[str[i] - 'a'] = 1;
        }
        if (!flag) {
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}
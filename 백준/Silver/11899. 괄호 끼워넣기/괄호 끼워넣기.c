#include <stdio.h>
#include <string.h>
char stack[51];
int top = -1;
int main() {
    char buf[51];
    scanf("%s", buf);
    int cnt = 0;
    for (int i = 0; i < strlen(buf); i++) {
        if (buf[i] == '(') {
            stack[++top] = buf[i];
        }
        else if (buf[i] == ')') {
            if (top == -1 || stack[top] != '(') {
                cnt++;
            }
            else {
                top--;
            }
        }
    }
    cnt += top + 1;
    printf("%d", cnt);



    return 0;
}

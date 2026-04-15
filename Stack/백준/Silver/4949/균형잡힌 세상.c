#include <stdio.h>


int isBalanced(char* str) {
    char temp[101];
    int top = -1;

    for (int i = 0; str[i] != '.'; i++) {
        if (str[i] == '(' || str[i] == '[') {
            temp[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == ']') {
            if (top == -1) {
                return 0; // 오른쪽 괄호가 왼쪽 괄호와 짝을 이룰 수 없음
            }
            char left = temp[top--];
            if ((str[i] == ')' && left != '(') || (str[i] == ']' && left != '[')) {
                return 0; // 괄호의 짝이 맞지 않음
            }
        }
    }

    return top == -1 ? 1 : 0; // 스택이 비어있으면 균형이 맞음
}

int main() {
    char str[101];

    while (1) {
        gets(str);

        if (strcmp(str,".")==0) {
            break; // 입력 종료 조건
        }

        int result = isBalanced(str);
        if (result) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}
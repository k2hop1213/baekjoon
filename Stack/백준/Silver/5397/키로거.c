#include <stdio.h>
#include <string.h>

#define MAX_STACK 1000001

typedef char element;

element stack[MAX_STACK];
element stack1[MAX_STACK];
int top = -1;   // 커서 앞 스택의 탑 인덱스
int top1 = -1;  // 커서 뒤 스택의 탑 인덱스

// 스택 연산 함수
void push(element *stack, int *top, element item) {
  stack[++(*top)] = item;
}

element pop(element *stack, int *top) {
  if (*top == -1) return -1; // 스택이 비어 있음
  return stack[(*top)--];
}

int isEmpty(int top) {
  return top == -1;
}

int main() {
  int a;
  scanf("%d", &a);
  getchar();  // 버퍼 클리어

  char str[MAX_STACK];
  for (int i = 0; i < a; i++) {
    fgets(str, MAX_STACK, stdin);
    int len = strlen(str) - 1; // 개행 문자 제거

    top = top1 = -1;  // 스택 초기화

    for (int j = 0; j < len; j++) {
      if (str[j] == '<') {
        if (!isEmpty(top)) {
          push(stack1, &top1, pop(stack, &top));
        }
      } else if (str[j] == '>') {
        if (!isEmpty(top1)) {
          push(stack, &top, pop(stack1, &top1));
        }
      } else if (str[j] == '-') {
        if (!isEmpty(top)) {
          pop(stack, &top);
        }
      } else {
        push(stack, &top, str[j]);
      }
    }

    // 출력: 스택에서 차례로 출력
    for (int j = 0; j <= top; j++) {
      putchar(stack[j]);
    }
    for (int j = top1; j >= 0; j--) {
      putchar(stack1[j]);
    }
    putchar('\n');  // 줄바꿈
  }

  return 0;
}

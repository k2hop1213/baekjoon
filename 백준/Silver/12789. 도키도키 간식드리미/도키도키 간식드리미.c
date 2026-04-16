#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 1000

typedef int element;

element stack[MAX_STACK];
element stack1[MAX_STACK];
int top = -1;
int top1 = -1;

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
  int n;
  scanf("%d", &n);
  int *arr = (int *)malloc(sizeof(int) * n); // 동적 메모리 할당
  int cnt = 1; // 현재 간식을 받을 번호

  // 입력
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // 배열을 역순으로 스택에 삽입
  for (int i = n - 1; i >= 0; i--) {
    push(stack, &top, arr[i]);
  }

  // 간식 배부 시뮬레이션
  while (!isEmpty(top) || !isEmpty(top1)) {
    // stack의 맨 위 값이 cnt와 같으면 pop
    if (!isEmpty(top) && stack[top] == cnt) {
      pop(stack, &top);
      cnt++;
    }
    // stack1의 맨 위 값이 cnt와 같으면 pop
    else if (!isEmpty(top1) && stack1[top1] == cnt) {
      pop(stack1, &top1);
      cnt++;
    }
    // stack의 값을 stack1으로 이동
    else if (!isEmpty(top)) {
      push(stack1, &top1, pop(stack, &top));
    }
    // 이동할 값이 없고 순서가 맞지 않으면 실패
    else {
      printf("Sad\n");
      free(arr); // 동적 메모리 해제
      return 0;
    }
  }

  // 성공적으로 정렬된 경우
  printf("Nice\n");
  free(arr); // 동적 메모리 해제
  return 0;
}

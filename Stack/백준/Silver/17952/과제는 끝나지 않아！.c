#include <stdio.h>

#define MAX_STACK 1000001

typedef int element;

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

  int n;
  scanf("%d",&n);
  int a, score, time;
  int res = 0;
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    if(a){
      scanf("%d %d",&score,&time);
      push(stack,&top,score);
      push(stack1,&top1,time);
      stack1[top1]--;
      if(stack1[top1]==0){
        res += pop(stack,&top);
        pop(stack1,&top1);
        }
    }
    else{
      if(stack1[top1]){
        stack1[top1]--;
        if(stack1[top1]==0){
          res += pop(stack,&top);
          pop(stack1,&top1);
        }
      }
      
    }
  }
  
  printf("%d",res);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
  int a = 0;
  scanf("%d",&a);
  int* arr= malloc(sizeof(int)*a);
  for(int i = 0;i<a;i++){
    scanf("%d",&arr[i]);
  }
  int cnt = 0;


  for (int i = a - 1; i > 0 ; i--) {
    if (arr[i - 1] >= arr[i]) {
        while (arr[i - 1] >= arr[i]) {  
          arr[i - 1]--;
          cnt++;
        }
    }
  }
  printf("%d",cnt);
  return 0;
}
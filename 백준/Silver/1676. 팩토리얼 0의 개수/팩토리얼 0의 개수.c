#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int cnt = 0;
  int temp = 1;
  for(int i = 1;i<=n;i++){
    if(i % 2 == 0 || i % 5 == 0){
      temp *= i;
      if(temp % 10 == 0){
        while(temp % 10 == 0){
          cnt++;
          temp/=10;
        }
        temp = 1;
      }
    }
  }
  printf("%d",cnt);

  
}
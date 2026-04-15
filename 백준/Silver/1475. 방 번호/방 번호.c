#include <stdio.h>

int main(){
  int a;
  
  scanf("%d",&a);
  
  int num[10]={0};
  
  while(a>0){
    int temp = a%10;
    num[temp]++;
    a/=10;
  }
  
  int max=0;

  for(int i=0;i<10;i++){
    if((i != 6 && i != 9) && max<num[i]){
      max=num[i];
    }
  }

  int sum = (num[6] + num[9] + 1) / 2;

  if(max< sum) max = sum;
  printf("%d",max);
  
  return 0;
}
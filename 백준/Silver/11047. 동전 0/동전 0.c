#include <stdio.h>
#include <stdlib.h>

int main(){
  int a,b;
  scanf("%d %d",&a,&b);

  int *arr=(int*)malloc(sizeof(int)*a);

  for(int i=0;i<a;i++){
    scanf("%d",&arr[i]);
  }
  int count = 0;
  for(int i = a-1;i>=0;i--){
    if (arr[i] <= b) { 
        count += b / arr[i]; 
        b %= arr[i]; 
    }
    if(b==0)break;
  }

  printf("%d",count);
  
}
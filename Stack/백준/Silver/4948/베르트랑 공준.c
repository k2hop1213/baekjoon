#include <stdio.h>

int isPrime(int n){
  if(n == 1){
    return 0;
  }
  if(n == 2){
    return 1;
  }
  
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int a;
  int cnt = 0;
  while(1){
    scanf("%d",&a);
    if(a==0){
      break;
    }
    for(int i = a + 1 ; i<= 2*a;i++){
      if(isPrime(i)){
        cnt++;
      }
    }
    printf("%d\n",cnt);
    cnt=0;
  }


  return 0;
}
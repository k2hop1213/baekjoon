#include <stdio.h>
#include <stdlib.h>
int main(){
  long long int A,B;
  scanf("%lld %lld",&A,&B);
  int cnt =0;
  while (B >= A) {
    if (B == A) {
        printf("%d", cnt + 1);
        return 0;
    }
    if (B % 10 == 1) {
        B /= 10;
        cnt++;
    } else if (B % 2 == 0) {
        B /= 2;
        cnt++;
    } else {
        break;
    }
  }

  printf("-1");
  
  
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(){
  long long int n;
  scanf("%d",&n);
  long long int *lit = (long long int*)malloc(sizeof(long long int)*(n-1));
  long long int *cost = (long long int*)malloc(sizeof(long long int)*n);
  for(int i=0;i<n-1;i++)scanf("%d",&lit[i]);
  for(int i=0;i<n;i++)scanf("%d",&cost[i]);

  long long int res = lit[0]*cost[0];
  long long int temp = cost[0];
  for(int i = 1; i <= n-2;i++){
    if(temp > cost[i]){
      temp = cost[i];
    }
    res += lit[i] * temp;
  }
  
  printf("%lld",res);
  return 0;
}
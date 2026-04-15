#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(){
  int N,L;

  scanf("%d %d",&N,&L);

  int* arr=malloc(sizeof(int)*N);

  for(int i=0;i<N;i++)scanf("%d",&arr[i]);
  
  qsort(arr,N,sizeof(int),compare);

  int cnt = 1;
  double cover = arr[0] + L - 0.5;  

  for (int i = 1; i < N; i++) {
      if (arr[i] + 0.5 > cover) { 
          cnt++;
          cover = arr[i] + L - 0.5;
      }
  }
  
  printf("%d",cnt);
  return 0;
}
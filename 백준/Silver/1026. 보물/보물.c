#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare1(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(){
  int n;
  scanf("%d",&n);

  int *arr1=(int*)malloc(sizeof(int)*n);
  int *arr2=(int*)malloc(sizeof(int)*n);

  for(int i=0;i<n;i++){
    scanf("%d",&arr1[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&arr2[i]);
  }

  qsort(arr1, n, sizeof(int), compare);
  qsort(arr2, n, sizeof(int), compare1);

  int res = 0;

  for(int i = 0;i<n;i++){
    res+=arr1[i]*arr2[i];
  }
  printf("%d",res);
}
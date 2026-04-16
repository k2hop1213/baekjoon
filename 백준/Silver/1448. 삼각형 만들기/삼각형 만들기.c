#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b) {
    return -1;
  }
  else if (*(int*)a < *(int*)b) {
    return 1;
  }
  else {
    return 0;
  }
} 


int main() {
  int n;
  scanf("%d", &n);
  int* arr = malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  qsort(arr, n, sizeof(int), compare);
  int tf = 0;
  for (int i = 0; i < n - 2; i++) {
    if (arr[i] < arr[i + 1] + arr[i + 2]) {
      printf("%d", arr[i] + arr[i + 1] + arr[i + 2]);
      tf = 1;
      break;
    }
  } 

  if (tf == 0) {
    printf("-1");
  } 

  return 0;
}
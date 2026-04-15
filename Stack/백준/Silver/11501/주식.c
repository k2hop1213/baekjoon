#include <stdio.h>
#include <stdlib.h>
int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
      int N;
      scanf("%d", &N);

      int *arr = (int *)malloc(sizeof(int) * N);
      for (int i = 0; i < N; i++) {
          scanf("%d", &arr[i]);
      }

      long long max_profit = 0;  
      int max_price = 0;        

      for (int i = N - 1; i >= 0; i--) {
          if (arr[i] > max_price) {
              max_price = arr[i];  
          } else {
              max_profit += (max_price - arr[i]);  
          }
      }

      printf("%lld\n", max_profit);
      free(arr);
  }
  
  return 0;
}
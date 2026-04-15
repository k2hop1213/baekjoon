#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
   unsigned long long N;
   int pownum = 64;
   scanf("%llu", &N);
   for (; pownum >= 1; pownum--) {
      if (N % 2) {
         break;
      }
      N /= 2;
   }
   printf("%d", pownum);
   return 0;
}
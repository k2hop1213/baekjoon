#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
   int n;
   scanf("%d", &n);
   char** s;
   s = (char**)malloc(sizeof(char*) * n);
   for (int i = 0; i < n; i++) {
      s[i] = (char*)malloc(sizeof(char) * 100000);
   }
   for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
   }
   for (int i = 0; i < n; i++) {
      int cnt_arr[26] = { 0 };
      int len = strlen(s[i]);
      int fake = 0;
      for (int k = 0; k < len; k++) {
         cnt_arr[s[i][k] - 'A']++;
         if (cnt_arr[s[i][k] - 'A'] % 3 == 0 && cnt_arr[s[i][k] - 'A'] != 0) {
            if (s[i][k] != s[i][k + 1]) {
               fake = 1;
               break;
            }
            k++;
         }
      }
      if (fake)
         printf("FAKE\n");
      else
         printf("OK\n");
   }
   for (int i = 0; i < n; i++) {
      free(s[i]);
   }
   free(s);
   return 0;
}
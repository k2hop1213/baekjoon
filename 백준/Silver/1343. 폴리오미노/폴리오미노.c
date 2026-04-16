#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char arr[51];
  scanf("%s",arr);
  char a[5]="AAAA";
  char b[3]="BB";
  int check = 0;
  int index = 0;
  for(int i = 0;i<strlen(arr);i++){
    if(arr[i] == '.'){
      index++;
    }
    else{
      check = 0;
      while (i < strlen(arr) && arr[i] == 'X') {
        check++;
        i++;
      }
      if(check % 2){
        printf("-1");
        return 0;
      }
      else{
        while(check > 0){
          if(check >= 4){
            for(int j = index;j< index+4;j++){
              arr[j]='A';
              check--;
            }
            index+=4;
          }
          else{
            for(int j = index;j< index+2;j++){
              arr[j]='B';
              check--;
            }
            index+=2;
          }
        }
    }
    
    i--;
    }
  }
  for(int i = 0;i<strlen(arr);i++){
    printf("%c",arr[i]);
  }
  
  return 0;
}
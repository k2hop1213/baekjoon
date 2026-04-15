#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare1(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}
int main(){
  char str[100001];

  scanf("%s",str);
  int flag = 0;
  int val = 0;
  for(int i = 0;i<strlen(str);i++){
    if(str[i] =='0'){
      flag = 1;
    }
    val+=str[i]-'0';
  }
  if(flag && val % 3 ==0){
    qsort(str,strlen(str),sizeof(char),compare1);
    printf("%s",str);
  }
  else{
    printf("-1");
  }
}
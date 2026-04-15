#include <stdio.h>

int main(void)
{
	char arr[100] = {};
	char str[51] = {};
	scanf("%s", str);
	
	int left = 50, right = 50; //덱의 왼쪽 끝과 오른쪽 끝을 같은 곳에 위치 시켜둡니다.
	
	for(int i=0; str[i] != '\0'; i++) {
		if(arr[left] < str[i]) { //초기화를 0으로 했기에 처음 덱에 집어 넣을때는 덱의 오른쪽에 들어가게 됩니다.
			arr[right++] = str[i]; //값을 넣은 다음 right을 1 증가 시킵니다.
		} else arr[--left] = str[i]; //right와는 달리 left는 먼저 1 감소 시킨다음 값을 집어넣습니다.
	}
	
	for(int i=left; i<right; i++)
		printf("%c", arr[i]);
}
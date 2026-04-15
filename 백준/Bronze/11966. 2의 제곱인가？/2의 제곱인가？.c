#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int flag = 1;
	while (n > 0) {
		
		if (n != 1 && n % 2 == 1) {
			flag = 0;
			break;
		}
		n = n >> 1;
	}
	printf("%d", flag);


	return 0;
}
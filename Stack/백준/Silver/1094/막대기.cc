#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
int main() {
	int X = 0;
	scanf("%d", &X);
	int cnt = 0;
	while (X > 0) {
		if (X & 1) {
			cnt++;
		}
		X >>= 1;
	}
	printf("%d", cnt);
	return 0;
}
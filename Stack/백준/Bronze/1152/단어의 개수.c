#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char a[1000001];
	gets(a);
	int cnt = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') {
			cnt++;
		}
	}
	if (a[0] == ' ') {
		cnt--;
	}
	if (a[strlen(a) - 1] == ' ') {
		cnt--;
	}
	printf("%d", cnt + 1);
	return 0;
}
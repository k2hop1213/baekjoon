#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#if 1
int main() {
	char a[51];
	scanf("%s", a);
	char b[4] = "??!";
	char c[55];
	strcpy(c,strcat(a, b));
	printf("%s", c);

	return 0;
}

#endif
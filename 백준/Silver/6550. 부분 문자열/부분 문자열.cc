#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char* strstr1(char* str1, char* str2) {
	char* ptr1 = str1;
	char* ptr2 = str2;
	int len = 0;
	while (*ptr2 != NULL) {
		len++;
		ptr2++;
	}
	ptr2 = str2;
	while (*ptr2 != NULL) {
		if (*ptr1 == NULL) {
			return NULL;
		}
		if (*(ptr1) == *(ptr2)) {
			ptr2++;
			ptr1++;
		}
		else {
			ptr1++;
		}

	}
	return ptr1 - len;

}
int main() {

	char str1[100001] = { 0 };
	char str2[100001] = { 0 };
	char* ptr;
	while (scanf("%s %s", str1, str2) != EOF) {
		ptr = strstr1(str2, str1);
		if (ptr != NULL)printf("Yes");
		else printf("No");
		printf("\n");
	}
	return 0;
}
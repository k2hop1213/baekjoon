#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char arr[8];
	for (int i = 0; i < 8; i++)scanf("%hhd", &arr[i]);
	char temp[7] = { 0 };

	unsigned char* ptr = arr;
	for (int i = 0; i < 7; i++) {
		temp[i] = *(ptr + i + 1) - *(ptr + i);

	}
	int flag = 0;
	for (int i = 0; i < 7; i++) {
		if (temp[i] > 0) flag++;
	}

	if (flag == 7) printf("ascending");
	else if (flag > 0) printf("mixed");
	else printf("descending");

	return 0;
}
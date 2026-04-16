#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void ROT13(char* str) {
	while (*str != '\0') {
		if (*(str) >= 'a' && *(str) <= 'z') {
			if (*str + 13 > 'z') {
				*str -= 13;
			}
			else *str += 13;
		}
		else if (*(str) >= 'A' && *(str) <= 'Z') {
			if (*str + 13 > 'Z') {
				*str -= 13;
			}
			else *str += 13;
		}
		str++;
	}

}

int main() {
	char str[101];
	gets(str);
	ROT13(str);
	printf("%s", str);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char S[101];
	scanf("%s", S);
	
	int check_alpha1[26] = { 0 };
	int check_alpha2[26] = { 0 };
	for (int i = 0; i < strlen(S); i++) {
		if (check_alpha2[S[i] - 'a']) {
			continue;
		}
		check_alpha1[S[i] - 'a'] = i;
		check_alpha2[S[i] - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++) {
		if (check_alpha1[i] == 0 && check_alpha2[i] == 0) {
			check_alpha1[i] = -1;
		}
		printf("%d ", check_alpha1[i]);
	}
	return 0;
}
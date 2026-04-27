#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	long long length;
	int multiplier;
} Node;

Node stack[101];
int top = -1;

int main() {
	char str[101];
	scanf("%s", str);

	long long current_len = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			current_len--;
			int k = str[i - 1] - '0';

			top++;
			stack[top].length = current_len;
			stack[top].multiplier = k;

			current_len = 0;
		}
		else if (str[i] == ')') {
			long long final_inside = current_len * stack[top].multiplier;
			current_len = stack[top].length + final_inside;
			top--;
		}
		else {
			current_len++;
		}
	}

	printf("%lld\n", current_len);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int stack[105];
int top = -1;

int main() {
	char buf[105];
	scanf("%s", buf);
	int val = 0;
	int res = 0;
	for (int i = 0; buf[i]; i++) {
		if (buf[i] == '(') {
			stack[++top] = 0;
		}
		else if (buf[i] == 'C') {
			stack[++top] = 12;
		}
		else if (buf[i] == 'H') {
			stack[++top] = 1;
		}
		else if (buf[i] == 'O') {
			stack[++top] = 16;
		}
		else if (buf[i] >= '2' && buf[i] <= '9') {
			stack[top] *= (buf[i] - '0');
		}
		else if (buf[i] == ')') {
			int temp = 0;
			while (top != -1) {
				
				if (stack[top] == 0) {
					stack[top] += temp;
					break;
				}
				temp += stack[top--];
			}
		}
	}
	int temp = 0;
	while (top != -1) {
		temp = stack[top--];
		stack[top] += temp;
	}
	printf("%d", stack[0]);

	return 0;
}
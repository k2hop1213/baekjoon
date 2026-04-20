#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 101

char stack[MAX_SIZE];
int top;

void init_stack(void) {
	top = -1;
}

int is_empty(void) {
	return (top == -1);
}

int is_full(void) {
	return (top == MAX_SIZE - 1);
}

void push(char item) {
	if (!is_full()) {
		stack[++top] = item;
	}
}

char pop(void) {
	if (is_empty()) {
		return '\0';
	}
	return stack[top--];
}

// 이 위로 수정 금지
int calculate_vps(char* s) {
	init_stack();
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			push(s[i]);
		else {
			if (is_empty())
				return 0;
			if ((s[i] == ')' && stack[top] != '(') || (s[i] == '}' && (stack[top] != '{') || (s[i] == ']' && stack[top] != '[')))
				return 0;
			pop();
		}
	}
	if (!is_empty())
		return 0;

	init_stack();
	int depth = 1;
	int val = 0;
	int res = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			depth *= 2;
			push(s[i]);
			continue;
		}
		else if (s[i] == '[') {
			depth *= 3;
			push(s[i]);
			continue;
		}
		

		if (s[i] == ')') {
			//printf("%d %d\n",depth,val);
			pop();
			val = depth;
			depth /= 2;
			if (depth == 1) {
				if (s[i - 1] == ')' || s[i - 1] == ']') {

				}
				else res += val;
				val = 0;
			}
			else {
				if (s[i - 1] == ')' || s[i - 1] == ']') {

				}
				else res += val;
			}

			continue;
		}
		else if (s[i] == ']') {
			//printf("%d %d\n",depth,val);
			pop();
			val = depth;
			depth /= 3;
			if (depth == 1) {
				if (s[i - 1] == ')' || s[i - 1] == ']') {

				}
				else res += val;
				val = 0;
			}
			else {
				if (s[i - 1] == ')' || s[i - 1] == ']') {

				}
				else res += val;
			}


			continue;
		}

	}
	return res;
}
int main() {

	char buf[31];
	scanf("%s", buf);
	printf("%d",calculate_vps(buf));

	return 0;
}
#include <stdio.h>

int top = -1;
char stack[101];

void push(char a) {
	stack[++top] = a;
}

char pop() {

	if (top == -1)return 0;
	return stack[top--];
}

int func2(char c) {

	if (c == '(' || c == ')')return 0;
	if (c == '+' || c == '-')return 1;
	if (c == '/' || c == '*')return 2;

}

void func1(char* str) {
	int i = 0;

	while (str[i] != '\0') {
		char cur = str[i++];

		if ((cur >= '0' && cur <= '9') || (cur >= 'A' && cur <= 'Z')) {
			printf("%c", cur);
		}
		else {
			if (cur == '(') {
				push(cur);
			}
			else if (cur == ')') {

				while (top != -1) {
					if (stack[top] == '(')break;
					printf("%c", pop());
				}
				pop();
			}
			else if (cur == '+' || cur == '-' || cur == '*' || cur == '/') {
				
				while (top != -1) {
					char t = stack[top];
					if (func2(cur) <= func2(t)) {

						printf("%c", stack[top]);
						pop();
					}
					else break;
				}
				push(cur);

			}


		}
	}
	while (top != -1)printf("%c", pop());


}



int main() {
	
	char buf[101];
	scanf("%s", buf);
	func1(buf);

	return 0;
}
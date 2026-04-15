#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1000001

char input[MAX];
char stack[MAX];
int top = -1;

int main() {
	scanf("%s", input);

	int len = strlen(input);

	for (int i = 0; i < len; i++) {
		// 1. 우선 스택에 문자를 넣음
		stack[++top] = input[i];

		// 2. 스택의 마지막 4글자가 "PPAP"인지 확인
		// top이 3 이상이어야 4글자 확인 가능
		if (top >= 3) {
			if (stack[top - 3] == 'P' &&
				stack[top - 2] == 'P' &&
				stack[top - 1] == 'A' &&
				stack[top] == 'P') {

				// 3. "PPAP"가 맞다면 뒤의 3글자를 지움 (결과적으로 P 하나만 남김)
				top -= 3;
			}
		}
	}

	// 최종 결과 확인: 스택에 'P' 하나만 남아있어야 함
	if (top == 0 && stack[0] == 'P') {
		printf("PPAP");
	}
	else {
		printf("NP");
	}

	return 0;
}
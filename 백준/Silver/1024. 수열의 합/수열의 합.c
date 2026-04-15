#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	int N, L;
	scanf("%d %d", &N, &L);

	for (int length = L; length <= 100; length++) {
		int sum = (length * (length - 1)) / 2; // 연속된 정수의 합 계산

		if ((N - sum) % length == 0 && (N - sum) / length >= 0) {
			int start = (N - sum) / length;
			for (int i = 0; i < length; i++) {
				printf("%d ", start + i);
			}
			return 0;
		}
	}

	printf("-1\n"); // 조건을 만족하는 수열을 찾지 못한 경우
	return 0;
}
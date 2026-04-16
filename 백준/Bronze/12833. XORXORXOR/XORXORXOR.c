#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (C % 2) {
		A = A ^ B;
	}
	printf("%d", A);



	return 0;
}

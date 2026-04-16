#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {

	int baguni[100] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= M; a++) {
		int i, j, k = 0;
		scanf("%d %d %d", &i, &j, &k);
		for (int b = i; b <= j; b++) {
			baguni[b - 1] = k;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", baguni[i]);
	}
	


	return 0;
}

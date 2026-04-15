#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int baguni[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		baguni[i] = i + 1;
	}
	
	int N, M;
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= M; a++) {
		int i, j= 0;
		int temp = 0;
		scanf("%d %d", &i, &j);
		temp = baguni[i - 1];
		baguni[i - 1] = baguni[j - 1];
		baguni[j - 1] = temp;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", baguni[i]);
	}


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int arraysum(int** arr, int* index, int M) {
	int sum = 0;
	for (int i = index[0] - 1; i <= index[2] - 1; i++) {
		for (int k = index[1] - 1; k <= index[3] - 1; k++) {
			sum += arr[i][k];
		}
	}

	return sum;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) arr[i] = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < N; i++) for (int k = 0; k < M; k++) scanf("%d", &arr[i][k]);

	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int index[4] = { 0 };
		for (int k = 0; k < 4; k++) scanf("%d", &index[k]);
		printf("%d\n", arraysum(arr, index, M));
	}

	for (int i = 0; i < N; i++) free(arr[i]);
	free(arr);
	return 0;
}
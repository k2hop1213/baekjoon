#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main() {
	int N;
	int prod = 1;
	scanf("%d", &N);
	int* arr;
	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	if (N == 1) {
		printf("%d", arr[0] * arr[0]);
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N - 1; k++) {
				if (arr[k] > arr[k + 1]) {
					int temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}
		prod = arr[0] * arr[N-1];
		printf("%d", prod);
	}
	free(arr);
	return 0;
}
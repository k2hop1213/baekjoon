#include <stdio.h>

int main() {
	int N, M, R;
	scanf("%d %d %d", &N, &M, &R);

	int A[300][300]; // 배열 크기의 최대값으로 배열 선언

	// 배열 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int minDim = N < M ? N : M;

	for (int r = 0; r < R; r++) {
		for (int layer = 0; layer < minDim / 2; layer++) {
			int first = A[layer][layer];
			int i, j;

			// 위쪽 행 오른쪽으로 이동
			for (j = layer; j < M - layer - 1; j++) {
				A[layer][j] = A[layer][j + 1];
			}

			// 오른쪽 열 아래로 이동
			for (i = layer; i < N - layer - 1; i++) {
				A[i][M - layer - 1] = A[i + 1][M - layer - 1];
			}

			// 아래쪽 행 왼쪽으로 이동
			for (j = M - layer - 1; j > layer; j--) {
				A[N - layer - 1][j] = A[N - layer - 1][j - 1];
			}

			// 왼쪽 열 위로 이동
			for (i = N - layer - 1; i > layer + 1; i--) {
				A[i][layer] = A[i - 1][layer];
			}

			A[layer + 1][layer] = first;
		}
	}

	// 결과 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	int N;
	scanf("%d", &N);
	int a[100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int v;
	scanf("%d", &v);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] == v) {
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
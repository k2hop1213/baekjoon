#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int countDigits(int number) {
	int count = 0;
	while (number > 0) {
		number /= 10;
		count++;
	}
	return count;
}

int main() {
	int N, k;
	scanf("%d %d", &N, &k);

	int i = 1;
	while (i <= N) {
		int digits = countDigits(i);
		if (k <= digits) {
			printf("%d", i / (int)pow(10, digits - k) % 10);
			return 0;
		}
		k -= digits;
		i++;
	}

	printf("-1");
	return 0;
}

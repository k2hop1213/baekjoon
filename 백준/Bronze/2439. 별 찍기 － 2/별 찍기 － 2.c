#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int check = 0;
	for (int i = 0; i < n; i++) {
		check++;
		for (int k = 0; k < n - check; k++) {
			printf(" ");
		}
		for (int k = 0; k < check; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int check_arr[30];
	for (int i = 0; i < 30; i++) {
		check_arr[i] = i + 1;
	}
	for (int i = 0; i < 28; i++) {
		int check = 0;
		scanf("%d", &check);
		check_arr[check - 1] = 0;
	}
	for (int i = 0; i < 30; i++) {
		if (check_arr[i]) {
			printf("%d\n", check_arr[i]);
		}
	}
	return 0;
}
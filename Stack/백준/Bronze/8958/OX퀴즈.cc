
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    char** arr = (char**)malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(sizeof(char) * 80);
    }


    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        int temp = 0;
        for (int k = 0; k < strlen(arr[i]); k++) {
            if (*(arr[i] + k) - 'X') {
                temp++;
                sum += temp;
            }
            else temp = 0;
        }
        printf("%d\n", sum);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main() {
    char arr[5][16] = {0,}; 

    for (int i = 0; i < 5; i++) {
        scanf("%s", arr[i]);
    }

    int max_len = 0; 
    for (int i = 0; i < 5; i++) {
        int len = strlen(arr[i]);
        if (len > max_len) {
            max_len = len;
        }
    }


    for (int k = 0; k < max_len; k++) {
        for (int i = 0; i < 5; i++) {
            if (arr[i][k]) { 
                printf("%c", arr[i][k]);
            }
        }
    }

    return 0;
}
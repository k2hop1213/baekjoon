#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char str[1000001];
int main() {

    
    scanf("%s", str);
    int result1 = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            result1 += 1;
            while (str[i] == '0') {
                i++;
            }
        }

    }
    int result2 = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            result2 += 1;
            while (str[i] == '1') {
                i++;
            }
        }

    }
    int real = result1 < result2 ? result1 : result2;
    printf("%d", real);
    return 0;
}
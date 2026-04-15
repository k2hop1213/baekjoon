#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main() {
    char str[1000];
    gets(str);
    char** p = malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        p[i] = malloc(sizeof(char) * 1001);
    }
    for (int i = 0; i < strlen(str); i++) {
        p[i] = str + i;
    }
    for (int i = 0; i < strlen(str) - 1; i++) {
        for (int k = i + 1; k < strlen(str); k++) {
            if (strcmp(p[i], p[k]) > 0) {
                char* temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }
    for (int i = 0; i < strlen(str); i++) {
        printf("%s\n", p[i]);
    }
    

    return 0;
}
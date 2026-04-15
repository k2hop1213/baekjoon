#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char str[100001];
    gets(str);
    char* ptr = str;
    
    for (int i = 0; i < strlen(str); i++) {
        int index = 0;
        if (str[i] == '<') {
            while (1) {
                printf("%c", str[i]);
         
                if (str[i] == '>') {
                    break;
                }
                i++;
            }
        }
        else {
            int temp = i;
            while ((str[i] != '<' && str[i] != ' ') && str[i] != NULL) {
                index++;
                i++;
            }
            i = temp;
            for (int k = index + i - 1; k >= i; k--) {
                printf("%c", str[k]);
            }
            i += index - 1;
            if (str[i + 1] == ' ') {
                printf("%c", str[i + 1]);
                i++;
            }
        }
        
        
    }


    return 0;
}
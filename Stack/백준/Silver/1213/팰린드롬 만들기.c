#include <stdio.h>
#include <string.h>


int main() {
    char str[51];
    scanf("%s", str);
    int ap[26] = { 0 };
    for (int i = 0; i < strlen(str); i++) {
        ap[str[i] - 'A']++;
    }
    char result[51] = { 0 };
    int index = 0;
    if (strlen(str) % 2 == 0) {// 문자열 길이가 짝수이면서 그 문자열이 펠린드롬이 되려면 그 문자열을 구성하는 알파벳은 모두 짝수번 출현해야함
        for (int i = 0; i < 26; i++) {
            if (ap[i] % 2) {
                printf("I'm Sorry Hansoo");
                return 0;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (ap[i]) {
                for (int k = 0; k < ap[i] / 2; k++) {
                    result[index++] = i + 'A';
                }
            }
        }
        printf("%s", result);
        index = 0;
        for (int i = 25; i >= 0; i--) {
            if (ap[i]) {
                for (int k = 0; k < ap[i] / 2; k++) {
                    result[index++] = i + 'A';
                }
            }
        }
        printf("%s", result);
    }
    else {
        int cnt = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (ap[i] % 2) {
                cnt++;
                mid = i + 'A';
            }
        }
        if (cnt > 1) { // 문자열 길이가 홀수이면 딱 하나의 문자만 홀수번 출현할 수 있고 나머지는 다 짝수번 출현해야함
            printf("I'm Sorry Hansoo");
            return 0;
        }
        for (int i = 0; i < 26; i++) {
            if (ap[i]) {
                for (int k = 0; k < ap[i] / 2; k++) {
                    result[index++] = i + 'A';
                }
            }
        }
        printf("%s", result);
        printf("%c", mid);
        index = 0;
        for (int i = 25; i >= 0; i--) {
            if (ap[i]) {
                for (int k = 0; k < ap[i] / 2; k++) {
                    result[index++] = i + 'A';
                }
            }
        }
        printf("%s", result);
    
    }

    return 0;
}
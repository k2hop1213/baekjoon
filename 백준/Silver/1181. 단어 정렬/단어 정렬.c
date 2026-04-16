#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열 비교 함수 (길이가 짧은 것부터, 길이가 같으면 사전 순으로)
int compareStrings(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    // 길이 비교
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return len1 - len2;
    }

    // 길이가 같으면 사전 순으로 비교
    return strcmp(str1, str2);
}

int main() {
    int n;
    scanf("%d", &n);

    char** words = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        words[i] = malloc(sizeof(char) * 51);
        scanf("%s", words[i]);
    }

    // 문자열 정렬
    qsort(words, n, sizeof(char*), compareStrings);

    // 중복 제거하고 정렬된 단어 출력
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1]) != 0) {
            printf("%s\n", words[i]);
        }
    }

    // 할당된 메모리 해제
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

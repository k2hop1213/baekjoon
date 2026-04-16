#include <stdio.h>
#include <ctype.h>

int main() {
    char word[1000001];
    int count[26] = {0};  // 알파벳의 빈도를 저장할 배열

    // 알파벳 대소문자로 이루어진 단어 입력
    scanf("%s", word);

    // 알파벳의 빈도 계산
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            // 알파벳인 경우에만 빈도 증가
            int index = toupper(word[i]) - 'A';
            count[index]++;
        }
    }

    // 가장 많이 사용된 알파벳 찾기
    int maxCount = 0;
    char result = '?';

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = 'A' + i;
        } else if (count[i] == maxCount) {
            // 빈도가 같은 알파벳이 여러 개인 경우 '?'로 설정
            result = '?';
        }
    }

    // 결과 출력
    printf("%c\n", result);

    return 0;
}

#include <stdio.h>

int main() {
    char S[1001];
    int i;

    // 단어 S 입력
    scanf("%s", S);

    // 인덱스 i 입력
    scanf("%d", &i);

    // i번째 글자 출력
    printf("%c\n", S[i - 1]);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int T, R;
    char S[21];

    // 테스트 케이스의 개수 입력
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        // 반복 횟수와 문자열 입력
        scanf("%d %s", &R, S);

        // 문자열의 각 문자를 R번 반복하여 출력
        for (int j = 0; j < strlen(S); j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }

        // 줄 바꿈
        printf("\n");
    }

    return 0;
}

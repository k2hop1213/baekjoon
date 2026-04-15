#include <stdio.h>

int main() {
    int H, M;

    // 알람 시간 입력
    scanf("%d %d", &H, &M);

    // 45분을 뺀다.
    M -= 45;

    // M이 음수이면 60분을 더하고 H를 1 줄인다.
    if (M < 0) {
        M += 60;
        H--;
    }

    // H가 음수이면 24를 더한다.
    if (H < 0) {
        H += 24;
    }

    // 결과 출력
    printf("%d %d\n", H, M);

    return 0;
}

#include <stdio.h>

int main() {
    int T; // 테스트 케이스 개수
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int H, W, N; // 호텔의 층 수, 각 층의 방 수, N 번째 손님
        scanf("%d %d %d", &H, &W, &N);

        int floor = N % H; // 손님이 머무는 층 수
        int room = N / H + 1; // 손님이 머무는 층에서의 방 번호

        // 만약 손님이 맨 꼭대기 층에 머무를 경우
        if (floor == 0) {
            floor = H;
            room--;
        }

        // 결과 출력
        printf("%d%02d\n", floor, room);
    }

    return 0;
}

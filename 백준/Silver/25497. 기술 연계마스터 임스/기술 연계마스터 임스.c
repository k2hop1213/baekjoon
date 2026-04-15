#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char skills[200001];

    // 입력 받기
    scanf("%d", &N);
    scanf("%s", skills);

    int count = 0; // 정상 발동된 기술의 수
    int L_count = 0; // 사용 가능한 L의 수
    int S_count = 0; // 사용 가능한 S의 수
    int corrupted = 0; // 스크립트가 꼬였는지 여부

    for (int i = 0; i < N; i++) {
        char skill = skills[i];

        if (corrupted) {
            break; // 스크립트가 꼬인 경우 종료
        }

        // 1~9는 연계 없이 사용할 수 있는 기술
        if ('1' <= skill && skill <= '9') {
            count++;
        } 
        // L은 R의 사전 기술
        else if (skill == 'L') {
            L_count++;
        } 
        // S는 K의 사전 기술
        else if (skill == 'S') {
            S_count++;
        } 
        // R은 L과 연계하여 사용 가능
        else if (skill == 'R') {
            if (L_count > 0) {
                count++;
                L_count--; // L 사용 횟수 감소
            } else {
                corrupted = 1; // 스크립트 꼬임 발생
            }
        } 
        // K는 S와 연계하여 사용 가능
        else if (skill == 'K') {
            if (S_count > 0) {
                count++;
                S_count--; // S 사용 횟수 감소
            } else {
                corrupted = 1; // 스크립트 꼬임 발생
            }
        }
    }

    // 결과 출력
    printf("%d\n", count);

    return 0;
}
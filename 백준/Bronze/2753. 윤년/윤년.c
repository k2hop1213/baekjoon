#include <stdio.h>

int main() {
    int year;

    // 연도 입력
    scanf("%d", &year);

    // 윤년 여부 판단
    int isLeapYear = 0;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = 1;
    }

    // 결과 출력
    printf("%d\n", isLeapYear);

    return 0;
}

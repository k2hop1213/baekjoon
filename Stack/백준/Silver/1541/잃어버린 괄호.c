#include <stdio.h>
#include <string.h>

int main() {
    char expression[51];  // 최대 길이는 50
    scanf("%s", expression);

    int result = 0;
    int temp = 0;
    int isMinus = 0;  // `-` 연산자가 나온 후인지 여부

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '+') {
            // + 연산자는 단순히 현재 값에 더함
            if (isMinus) {
                result -= temp;
            } else {
                result += temp;
            }
            temp = 0;
        } else if (expression[i] == '-') {
            // - 연산자는 현재까지의 temp를 더하고, 이후부터는 모든 값을 빼야 함
            if (isMinus) {
                result -= temp;
            } else {
                result += temp;
            }
            temp = 0;
            isMinus = 1;  // 이제부터는 모든 값을 빼야 함
        } else {
            // 숫자일 경우 temp에 숫자 추가
            temp = temp * 10 + (expression[i] - '0');
        }
    }
    if (isMinus) {
        result -= temp;  // - 이후 마지막 숫자 처리
    } else {
        result += temp;  // + 이후 마지막 숫자 처리
    }

    printf("%d\n", result);
    return 0;
}

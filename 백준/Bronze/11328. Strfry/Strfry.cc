#include <stdio.h>
#include <string.h>

// 문자열을 정렬하는 함수 (버블 소트 사용)
void bubbleSort(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // 두 문자를 교환
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char str1[1001], str2[1001];
        scanf("%s %s", str1, str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);

        // 두 문자열을 정렬
        bubbleSort(str1);
        bubbleSort(str2);

        // 정렬된 문자열이 같으면 가능하다고 판단
        if (strcmp(str1, str2) == 0) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}

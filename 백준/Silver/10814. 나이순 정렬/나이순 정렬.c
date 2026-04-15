#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 회원 정보를 저장하는 구조체
typedef struct {
    int age;
    char name[101];
} Member;

// 비교 함수
int compareMembers(const void *a, const void *b) {
    // 나이 오름차순 정렬
    int ageDiff = ((Member *)a)->age - ((Member *)b)->age;

    // 나이가 같으면 가입 순서로 정렬
    if (ageDiff == 0) {
        return a < b ? -1 : 1;
    }

    return ageDiff;
}

int main() {
    int n;
    scanf("%d", &n);

    Member *members = malloc(sizeof(Member) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &members[i].age, members[i].name);
    }

    // qsort를 사용하여 회원을 나이 순, 나이가 같으면 가입한 순으로 정렬
    qsort(members, n, sizeof(Member), compareMembers);

    // 정렬된 회원 정보 출력
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }

    // 할당된 메모리 해제
    free(members);

    return 0;
}

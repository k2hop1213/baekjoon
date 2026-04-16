#include <stdio.h>
#include <stdlib.h>

// 지원자의 구조체 정의
typedef struct {
    int doc;  // 서류심사 순위
    int interview;  // 면접 순위
} Applicant;

// 정렬 함수 (서류 심사 성적을 기준으로 오름차순 정렬)
int compare(const void *a, const void *b) {
    return ((Applicant*)a)->doc - ((Applicant*)b)->doc;
}

int main() {
    int T;  // 테스트 케이스 개수
    scanf("%d", &T);
    
    while (T--) {
        int N;  // 지원자 수
        scanf("%d", &N);
        
        Applicant applicants[N];
        
        // 입력 받기
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &applicants[i].doc, &applicants[i].interview);
        }
        
        // 서류 심사 기준으로 정렬
        qsort(applicants, N, sizeof(Applicant), compare);
        
        int count = 1; // 첫 번째 지원자는 무조건 선발
        int bestInterviewRank = applicants[0].interview;
        
        // 면접 순위를 비교하며 선발 가능한 지원자 수 계산
        for (int i = 1; i < N; i++) {
            if (applicants[i].interview < bestInterviewRank) {
                count++;
                bestInterviewRank = applicants[i].interview; // 최소 면접 순위 갱신
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}

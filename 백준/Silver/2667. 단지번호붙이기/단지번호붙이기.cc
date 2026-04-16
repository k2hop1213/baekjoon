#include <stdio.h>
#include <stdlib.h>

#define MAX_N 25

// 방향을 나타내는 배열 (상, 하, 좌, 우)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int house_count[MAX_N * MAX_N]; // 각 단지별 집의 수를 저장하는 배열
int num_of_complex = 0; // 총 단지수

// DFS를 사용하여 단지 찾기
void dfs(int x, int y, int complex_num) {
    visited[x][y] = 1;
    house_count[complex_num]++; // 단지 내 집의 수 증가

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 유효한 범위 내에 있고, 아직 방문하지 않은 집이면 탐색
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, complex_num);
        }
    }
}

// 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    scanf("%d", &N);

    // 지도 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // 단지 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, num_of_complex++);
            }
        }
    }

    // 단지별 집의 수를 오름차순으로 정렬
    qsort(house_count, num_of_complex, sizeof(int), compare);

    // 결과 출력
    printf("%d\n", num_of_complex);
    for (int i = 0; i < num_of_complex; i++) {
        printf("%d\n", house_count[i]);
    }

    return 0;
}

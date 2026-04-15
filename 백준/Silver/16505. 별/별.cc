#include <bits/stdc++.h>
using namespace std;

// 별을 저장할 보드 (최대 2^10 = 1024)
vector<string> board;

/**
 * @brief Sierpinski 삼각형 패턴을 재귀적으로 그립니다.
 * * @param r 현재 삼각형 영역의 좌상단 행 인덱스
 * @param c 현재 삼각형 영역의 좌상단 열 인덱스
 * @param level 현재 재귀 레벨 (입력 N에서 시작하여 0으로 감소)
 */
void draw_triangle(int r, int c, int level) {

	// 1. 베이스 케이스: 레벨 0에 도달하면 최소 단위인 별을 찍고 종료
	if (level == 0) {
		board[r][c] = '*';
		return;
	}

	// 현재 레벨의 높이를 계산 (H = 2^level)
	int h = (1 << level);
	int half = h / 2; // 다음 레벨의 높이 (H/2)
	int next_level = level - 1; // 다음 재귀 레벨

	// 2. 상단 삼각형 재귀 호출: 시작점 (r, c)
	draw_triangle(r, c, next_level);

	// 3. 좌하단 삼각형 재귀 호출: 시작점 (r + half, c)
	draw_triangle(r + half, c, next_level);

	// 4. 우하단 삼각형 재귀 호출: 시작점 (r + half, c + half)
	// 중앙의 역삼각형 영역은 이 호출에서 제외되어 공백으로 남습니다.
	draw_triangle(r + half, c + half, next_level);
}

int main() {
	// 입출력 속도 향상
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	if (!(cin >> n)) return 0;

	// 전체 보드의 높이 H = 2^N
	int h = (1 << n);

	// 보드를 H x H 크기로 초기화하고, 공백 ' '으로 채웁니다.
	board.assign(h, string(h, ' '));

	// (0, 0)에서 시작하며, 입력 레벨 N을 전달합니다.
	draw_triangle(0, 0, n);

	// 결과 출력
	for (int i = h- 1; i >= 0; i--) {
		// 각 줄 끝에 필요없는 공백을 출력하지 않기 위해 
		// 문자열의 끝에서부터 '*' 문자가 있는 위치까지만 출력합니다.
		int last_star = -1;
		for (int j = h - 1; j >= 0; j--) {
			if (board[i][j] == '*') {
				last_star = j;
				break;
			}
		}
		// '*'가 있는 위치(last_star)까지 포함하여 출력
		cout << board[i].substr(0, last_star + 1) << '\n';
	}

	return 0;
}
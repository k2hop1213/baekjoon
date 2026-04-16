#include <bits/stdc++.h>

using namespace std;

// 3차원 좌표를 튜플로 사용: (H:높이/층, N:행, M:열) 순서
// board[h][n][m]

// 6방향 이동 정의: (h, n, m) 축의 변화량
// (1) 상하좌우: dz=0
// (2) 위층/아래층: dn=0, dm=0
int dh[6] = { 0, 0, 0, 0, 1, -1 }; // 높이/층 (위/아래)
int dn[6] = { 1, 0, -1, 0, 0, 0 }; // 행 (상/하)
int dm[6] = { 0, 1, 0, -1, 0, 0 }; // 열 (좌/우)

int board[102][102][102];

int main(void) {
	// 빠른 입출력
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 튜플은 (h, n, m) 순서로 사용: (높이, 행, 열)
	queue<tuple<int, int, int> > Q;

	int m, n, h; // 입력 순서: M(가로/열), N(세로/행), H(높이/층)
	cin >> m >> n >> h;

	// 1. 입력 및 초기 익은 토마토(1) 큐에 삽입
	for (int i = 0; i < h; i++) { // h: 층 (높이)
		for (int j = 0; j < n; j++) { // n: 행 (세로)
			for (int k = 0; k < m; k++) { // m: 열 (가로)
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					// 익은 토마토는 Q에 넣음 (h, n, m 순서)
					Q.push({ i, j, k });
				}
			}
		}
	}

	// 2. BFS 시작
	while (!Q.empty()) {
		// cur: (현재 층, 현재 행, 현재 열)
		tuple<int, int, int> cur = Q.front(); Q.pop();

		int cur_h = get<0>(cur);
		int cur_n = get<1>(cur);
		int cur_m = get<2>(cur);

		// 현재 칸의 일수 (토마토가 익는 데 걸린 시간)
		int day = board[cur_h][cur_n][cur_m];

		for (int dir = 0; dir < 6; dir++) { // 6방향(상하좌우 + 위층/아래층) 탐색
			int nh = cur_h + dh[dir]; // 다음 층
			int nn = cur_n + dn[dir]; // 다음 행
			int nm = cur_m + dm[dir]; // 다음 열

			// 3. 경계 검사: (0 <= nh < h), (0 <= nn < n), (0 <= nm < m)
			if (nh < 0 || nh >= h || nn < 0 || nn >= n || nm < 0 || nm >= m) {
				continue; // 범위를 벗어남
			}

			// 4. 익지 않은 토마토(0)일 경우에만 전파
			if (board[nh][nn][nm] == 0) {
				board[nh][nn][nm] = day + 1; // 익는 데 걸린 시간 기록
				Q.push({ nh, nn, nm });
			}
		}
	}

	// 5. 최종 검사 및 결과 출력
	int max_day = 0;

	for (int i = 0; i < h; i++) { // h: 층
		for (int j = 0; j < n; j++) { // n: 행
			for (int k = 0; k < m; k++) { // m: 열
				// 하나라도 익지 않은 토마토(0)가 남아있다면
				if (board[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
				// 최대 일수 갱신
				if (board[i][j][k] > max_day) {
					max_day = board[i][j][k];
				}
			}
		}
	}

	// 결과: 시작일(1일차)을 제외한, 추가로 걸린 일수
	// 만약 모든 토마토가 이미 익어있었다면 max_day는 1이므로 0을 출력
	cout << max_day - 1 << "\n";

	return 0;
}
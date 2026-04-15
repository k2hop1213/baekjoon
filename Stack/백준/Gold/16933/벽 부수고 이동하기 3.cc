#include <bits/stdc++.h>
using namespace std;

string board[1001];

int dis[1001][1001][11][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	fill(&dis[0][0][0][0], &dis[0][0][0][0] + 1001 * 1001 * 11 * 2, -1);

	queue<tuple<int, int, int, int>> Q;

	Q.push({ 0, 0, 0, 0 });
	dis[0][0][0][0] = 1;

	while (!Q.empty()) {
		tuple<int, int, int, int> cur = Q.front(); Q.pop();
		int cur_x = get<0>(cur);
		int cur_y = get<1>(cur);
		int cur_z = get<2>(cur);
		int cur_t = get<3>(cur); 
		int D = dis[cur_x][cur_y][cur_z][cur_t];

		if (cur_x == n - 1 && cur_y == m - 1) {
			cout << D;
			return 0;
		}

		int next_t = 1 - cur_t; 

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0') {
				if (dis[nx][ny][cur_z][next_t] == -1) {
					dis[nx][ny][cur_z][next_t] = D + 1;
					Q.push({ nx, ny, cur_z, next_t });
				}
			}

			else if (board[nx][ny] == '1' && cur_z < k) {
				int next_z = cur_z + 1;

				if (cur_t == 0) {
					if (dis[nx][ny][next_z][next_t] == -1) {
						dis[nx][ny][next_z][next_t] = D + 1;
						Q.push({ nx, ny, next_z, next_t });
					}
				}
				
			}
		}


		if (cur_t == 1) {
			int wait_t = 0;

			if (dis[cur_x][cur_y][cur_z][wait_t] == -1) {
				dis[cur_x][cur_y][cur_z][wait_t] = D + 1;
				Q.push({ cur_x, cur_y, cur_z, wait_t });
			}
		}
	}

	cout << -1;
	return 0;
}
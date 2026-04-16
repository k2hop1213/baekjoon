#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int sum[101][101];
int vis[101][101];
int vis1[101][101];
int dist[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>>Q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {// 섬 개수 세기
		for (int j = 0; j < n; j++) {
			if (vis[i][j])continue;
			if (board[i][j] == 1) {
				Q.push({ i,j });
				cnt++;
				sum[i][j] = cnt;
				vis[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int>cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (board[nx][ny] == 0 || vis[nx][ny])continue;

						vis[nx][ny] = 1;
						sum[nx][ny] = cnt;
						Q.push({ nx,ny });

					}

				}
			}
		}
	}

	fill(&vis[0][0], &vis[0][0] + 101 * 101, 0);

	for (int i = 1; i <= cnt; i++) { // 테두리 따기
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (sum[j][k] == i) {
					pair<int, int>cur = { j,k };
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (vis[j][k])continue;
						if (sum[nx][ny] == 0 && vis[nx][ny] == 0) {

							vis[j][k] = i;
						}

					}
					

				}
			}
		}
	}
	

	int res = n * n;
	for (int a = 1; a <= cnt; a++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis1[i][j] = 0;
				dist[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == a) {
					Q.push({ i,j });
					vis1[i][j] = 1;
				}
			}
		}

		bool found = false;
		while (!Q.empty()) {
			pair<int, int> cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (sum[nx][ny] == a || vis1[nx][ny]) continue; 

				if (sum[nx][ny] != 0 && sum[nx][ny] != a) { 
					res = min(res, dist[cur.first][cur.second]);
					found = true;
					break;
				}

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				vis1[nx][ny] = 1;
				Q.push({ nx, ny });
			}
			if (found) {
				while (!Q.empty()) Q.pop();
				break;
			}
		}
	}
	
	cout << res;

	return 0;
}
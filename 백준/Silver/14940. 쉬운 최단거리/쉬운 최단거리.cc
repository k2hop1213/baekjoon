#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>>Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2) {
				Q.push({ i,j });
				vis[i][j] == 1;
				dist[i][j] = 0;
				while (!Q.empty()) {
					pair<int, int>cur = Q.front(); Q.pop();
					int dis = dist[cur.first][cur.second];
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
						if (board[nx][ny] != 1 || vis[nx][ny])continue;

						dist[nx][ny] = dis + 1;
						vis[nx][ny] = 1;
						Q.push({ nx, ny });

					}


				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (vis[i][j] == 0 && board[i][j] == 1) cout << -1 << ' '; 
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}
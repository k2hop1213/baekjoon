#include <stdc++.h>
using namespace std;
int board[301][301];
int vis[301][301];
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

	int area = 0;
	int year = 0;
	queue<pair<int, int>>Q;
	int flag = 0;
	while (1) {
		fill(&vis[0][0], &vis[0][0] + 301 * 301, 0);
		area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0 && board[i][j]) {
					flag = 1;
					Q.push({ i,j });
					vis[i][j] = 1;
					area++;
					while (!Q.empty()) {
						pair<int, int>cur = Q.front(); Q.pop();
						for (int d = 0; d < 4; d++) {
							int nx = cur.first + dx[d];
							int ny = cur.second + dy[d];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
							if (vis[nx][ny])continue;
							if (board[nx][ny] == 0) {
								if (board[cur.first][cur.second] > 0) {
									board[cur.first][cur.second]--;
								}
								continue;
							}
							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}

				}
			}

		}
		if (flag == 0) {
			cout << 0;
			return 0;
		}
		else if (area >= 2) {
			cout << year;
			return 0;
		}
		year++;
		flag = 0;
	}


	return 0;
}

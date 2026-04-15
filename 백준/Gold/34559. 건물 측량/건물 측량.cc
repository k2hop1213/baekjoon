#include <bits/stdc++.h>
using namespace std;
string board[1001];
int vis[1001][1001];
int sum[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> board[i];
	queue<pair<int, int>>Q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (board[i][j] == '0' && vis[i][j] == 0) {
					
					Q.push({ i,j });
					vis[i][j] = 1;
					
				}
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (board[nx][ny] == '0' && vis[nx][ny] == 0) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i-1][j-1] != 1) 
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + 1 - sum[i - 1][j - 1];
			else
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int a;
	cin >> a;
	int res = 0;
	for (int i = 0; i < a; i++) {
		res = 0;
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		res = sum[x1][y1] - sum[x - 1][y1] - sum[x1][y - 1] + sum[x - 1][y - 1];
		if (res) cout << "No " << res << '\n';
		else cout << "Yes\n";

	}

	return 0;
}
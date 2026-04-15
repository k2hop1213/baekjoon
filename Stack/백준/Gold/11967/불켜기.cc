#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];
map<pair<int, int>, vector<pair<int, int>>>M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		M[{x,y}].push_back({ a,b });
	}
	queue<pair<int, int>>Q;
	Q.push({ 1,1 });
	board[1][1] = 1;
	vis[1][1] = 1;
	int cnt = 1;
	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();
		if (!M[cur].empty()) {
			for (auto a : M[cur]) {
				if (board[a.first][a.second] == 0) {
					board[a.first][a.second] = 1;
					cnt++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = dx[dir] + a.first;
						int ny = dy[dir] + a.second;
						if (nx < 1 || nx > n || ny < 1 || ny > n)continue;
						if (vis[nx][ny]) {
							if (!vis[a.first][a.second]) {
								Q.push({ nx,ny });
								vis[nx][ny] = 1;
							}
							break;
						}
					}
				}
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;
			if (nx < 1 || nx > n || ny < 1 || ny > n)continue;
			if (board[nx][ny] == 1 && !vis[nx][ny]) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}


	}
	cout << cnt;

	return 0;
}
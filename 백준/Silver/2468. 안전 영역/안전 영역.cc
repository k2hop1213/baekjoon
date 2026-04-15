#include <bits/stdc++.h>
using namespace std;
int board[102][102];
int vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			a = max(a, board[i][j]);
		}
	}
	int cnt = 0;
	queue<pair<int, int>> Q;
	int res = 0;
	for (int l = 1; l <= a; l++) {
		fill(&vis[0][0], &vis[0][0] + 102 * 102, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (vis[i][j] == 0 && board[i][j] > l) {
					cnt++;
					vis[i][j] = 1;
					Q.push({ i,j });
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = cur.first + dx[i];
							int ny = cur.second + dy[i];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
							if (vis[nx][ny] || board[nx][ny] <= l)continue;
							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}


			}
		}
		res = max(res, cnt);
		cnt = 0;
	}
	if (res == 0)cout << res + 1;
	else cout << res;
	return 0;
}
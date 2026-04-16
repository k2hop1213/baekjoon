#include <bits/stdc++.h>
using namespace std;


int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int board[51][51] = { 0, };
		int vis[51][51] = { 0, };
		int x, y;
		cin >> y >> x;
		if (x == 0 && y == 0)break;

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cin >> board[i][j];
			}
		}
		queue<pair<int, int>>Q;

		int cnt = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					Q.push({ i,j });
					cnt++;
					vis[i][j] = 1;
					while (!Q.empty()) {
						pair<int, int>cur = Q.front(); Q.pop();

						for (int dir = 0; dir < 8; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= x || ny < 0 || ny >= y)continue;
							if (board[nx][ny] == 0 || vis[nx][ny])continue;
							Q.push({ nx,ny });
							vis[nx][ny] = 1;
						}

					}
				}
			}
		}
		cout << cnt << '\n';

	}
	return 0;
}
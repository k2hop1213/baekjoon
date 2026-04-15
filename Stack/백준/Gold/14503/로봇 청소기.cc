#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int x, y, a;
	cin >> x >> y >> a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		int flag = 0;
		if (board[x][y] == 0) {
			cnt++;
			board[x][y] = 2;
		}
		for (int i = 0; i < 4; i++) {
			a = (a + 3) % 4;
			int nx = x + dx[a];
			int ny = y + dy[a];

			if (board[nx][ny] == 0) {
				x = nx;
				y = ny;
				flag = 1;
				break;
			}
			

		}
		if (!flag) {
			int nx = x - dx[a];
			int ny = y - dy[a];

			if (board[nx][ny] != 1) {
				x = nx;
				y = ny;
			}
			else {
				break;
			}

		}

	}

	cout << cnt;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int vis[1001][1001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = -1;
	}

	int x1, y1;
	cin >> x1 >> y1;

	int dir[4];
	vis[x1][y1] = 1;
	for (int i = 0; i < 4; i++)cin >> dir[i];
	int idx = 0;
	int cnt = 0;
	while(cnt < 4){
		int d = dir[idx];
		int nx = x1, ny = y1;


		if (d == 1) nx--;
		else if (d == 2) nx++;
		else if (d == 3) ny--;
		else if (d == 4) ny++;

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != -1 && !vis[nx][ny]) {
			x1 = nx;
			y1 = ny;
			vis[x1][y1] = 1;
			cnt = 0;
		}
		else {
			idx = (idx + 1) % 4;
			cnt++;
		}

	}

	cout << x1 << ' ' << y1 ;


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int board[201][201];
int vis[201][201][35];
int dis[201][201][35];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dx1[8] = { 2,2,1,1,-2,-2,-1,-1 };
int dy1[8] = { 1,-1,2,-2,1,-1,2,-2 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;

	int W, H;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}
	if (W == 1 && H == 1) {
		cout << 0;
		return 0;
	}

	queue<pair<pair<int, int>, int>>Q;
	Q.push({{ 0,0 }, 0});
	vis[0][0][0] = 1;
	while (!Q.empty()) {
		int cur_x = Q.front().first.first;
		int cur_y = Q.front().first.second;
		int cur_z = Q.front().second;
		Q.pop();
		if (cur_x == H - 1 && cur_y == W - 1) {
			cout << dis[cur_x][cur_y][cur_z];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
			if (board[nx][ny] || vis[nx][ny][cur_z])continue;
			vis[nx][ny][cur_z] = 1;
			dis[nx][ny][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
			Q.push({{ nx, ny }, cur_z});

		}
		if (cur_z < k) {
			for (int i = 0; i < 8; i++) {
				int nx = cur_x + dx1[i];
				int ny = cur_y + dy1[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (board[nx][ny] || vis[nx][ny][cur_z + 1])continue;
				vis[nx][ny][cur_z + 1] = 1;
				dis[nx][ny][cur_z + 1] = dis[cur_x][cur_y][cur_z] + 1;
				Q.push({ { nx, ny }, cur_z + 1 });
			}

		}
		

	}

	cout << -1;

	return 0;
}
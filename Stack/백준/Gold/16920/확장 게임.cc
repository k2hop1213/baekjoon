#include <bits/stdc++.h>
using namespace std;

string board[1001];
pair<int,int> arr[10];//이동할 수 있는 칸 수, 확장한 성의 수

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)cin >> arr[i].first;
	for (int i = 0; i < n; i++)cin >> board[i];

	queue<pair<int, int>>Q[10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				arr[board[i][j] - '0'].second++;
				Q[board[i][j] - '0'].push({ i,j });
			}
		}
	}
	
	while (1) {
		int flag = 0;
		for (int turn = 1; turn <= p; turn++) {

			
			for (int i = 0; i < arr[turn].first; i++) {
				int size = Q[turn].size();
				if (size == 0)break;
				while (size--) {
					pair<int, int>cur = Q[turn].front(); Q[turn].pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = dx[dir] + cur.first;
						int ny = dy[dir] + cur.second;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
						if (board[nx][ny] == '.') {
							board[nx][ny] = turn + '0';
							Q[turn].push({ nx,ny });
							arr[turn].second++;
							flag = 1;
						}
					}
				}
			}
			
		}
		if (flag == 0)break;
	}

	
	for (int i = 1; i <= p; i++)cout << arr[i].second << ' ';


	return 0;
}
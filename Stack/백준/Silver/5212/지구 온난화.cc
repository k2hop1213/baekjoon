#include <bits/stdc++.h>
using namespace std;

string board[11];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>>idx;
	queue<pair<int, int>>idx1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'X') {
				cnt = 0;
				if (i + 1 >= n) {
					cnt++;
				}
				else if (board[i + 1][j] == '.') {
					cnt++;
				}

				if (j + 1 >= m) {
					cnt++;
				}
				else if (board[i][j + 1] == '.') {
					cnt++;
				}

				if (i - 1 < 0) {
					cnt++;
				}
				else if (board[i - 1][j] == '.') {
					cnt++;
				}

				if (j - 1 < 0) {
					cnt++;
				}
				else if (board[i][j - 1] == '.') {
					cnt++;
				}

				if (cnt >= 3) {
					idx1.push({ i,j });
				}
				else {
					idx.push({ i,j });
				}
			}
		}
	}
	if (idx.size() == 1) {
		cout << 'X';
		return 0;
	}
	int max1 = 0;
	int max2 = 0;
	int min1 = 12;
	int min2 = 12;
	while (!idx1.empty()) {
		pair<int, int> cur = idx1.front(); idx1.pop();
		board[cur.first][cur.second] = '.';
	}
	while (!idx.empty()) {
		pair<int, int> cur = idx.front(); idx.pop();
		max1 = max(max1, cur.first);
		max2 = max(max2, cur.second);
		min1 = min(min1, cur.first);
		min2 = min(min2, cur.second);
	}

	for (int i = min1; i <= max1; i++) {
		for (int j = min2; j <= max2; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}


	return 0;
}
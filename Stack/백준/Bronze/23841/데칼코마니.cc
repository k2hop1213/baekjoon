#include <bits/stdc++.h>
using namespace std;

string board[51];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			if (board[i][j] != '.') {
				board[i][m - j - 1] = board[i][j];
			}
			else if (board[i][m - j - 1] != '.') {
				board[i][j] = board[i][m - j - 1];
			}
		}
	}


	for (int i = 0; i < n; i++)cout << board[i] << '\n';

	return 0;
}
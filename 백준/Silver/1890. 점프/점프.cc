#include <bits/stdc++.h>
using namespace std;

int board[101][101];
long long dp[101][101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	if (board[0][0] == 0) {
		cout << 0;
		return 0;
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

			int cur = board[i][j];

			if (i + cur < n) {
				dp[i + cur][j] += dp[i][j];
			}
			if (j + cur < n) {
				dp[i][j + cur] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}
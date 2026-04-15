#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dp[1005][1005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	dp[1][1] = board[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = max({ dp[i - 1][j],dp[i + 1][j],dp[i][j - 1],dp[i][j + 1] }) + board[i][j];

		}
	}
	cout << dp[n][m];

	return 0;
}
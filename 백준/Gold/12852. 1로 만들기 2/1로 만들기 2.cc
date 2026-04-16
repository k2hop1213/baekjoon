#include <bits/stdc++.h>
using namespace std;

int dp[2][1000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + 1;
		dp[1][i] = i - 1;
		if (i % 2 == 0) {
			dp[0][i] = min(dp[0][i / 2] + 1, dp[0][i]);
			if (dp[0][i] == dp[0][i / 2] + 1) dp[1][i] = i / 2;
		}
		if (i % 3 == 0) {
			dp[0][i] = min(dp[0][i / 3] + 1, dp[0][i]);
			if (dp[0][i] == dp[0][i / 3] + 1) dp[1][i] = i / 3;
		}

	}
	cout << dp[0][n] << '\n';
	
	int cur = n;
	cout << n << ' ';
	while (dp[1][cur] != 0) {
		cout << dp[1][cur] << ' ';
		cur = dp[1][cur];
	}

	return 0;
}
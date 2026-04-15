#include <bits/stdc++.h>
using namespace std;

int dp[31][31];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	for (int i = 3; i <= n; i++) {

		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)dp[i][j] = 1;
			else dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];

		}

	}


	cout << dp[n][k];


	return 0;
}
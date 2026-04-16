#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000

int main() {
	int N;
	cin >> N;

	long long dp[101][10];

	dp[1][0] = 0;
	for (int j = 1; j <= 9; j++) {
		dp[1][j] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % MOD;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % MOD;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
	long long total = 0;
	for (int j = 0; j <= 9; j++) {
		total = (total + dp[N][j]) % MOD;
	}

	cout << total;

	return 0;
}
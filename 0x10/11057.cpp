#include <stdc++.h>
using namespace std;
long long dp[1001][11];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {

		dp[i][9] = 1;
		for (int j = 8; j >= 0; j--) {
		
			dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % 10007;
		}
	}
	long long res = 0;

	for (int i = 0; i < 10; i++) {
		res = (res + dp[n][i]) % 10007;
	}

	cout << res;

	return 0;
}

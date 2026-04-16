#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	dp[1] = 1;
	for (int i = 2; i <= 1001; i++) {
		if (i % 2 == 0) dp[i] = dp[i - 1] + dp[i / 2];
		else dp[i] = dp[i - 1];
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
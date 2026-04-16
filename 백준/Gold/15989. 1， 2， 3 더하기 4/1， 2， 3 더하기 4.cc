#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= 10000; i++) {
		dp[i] = dp[i - 3] + i / 2 + 1;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}


	return 0;
}
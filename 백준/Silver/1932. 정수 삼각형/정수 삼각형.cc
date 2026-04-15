#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int arr[505][505];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	dp[2][1] = arr[2][1] + dp[1][1];
	dp[2][2] = arr[2][2] + dp[1][1];

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	cout << res;

	return 0;
}
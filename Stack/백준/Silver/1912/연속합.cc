#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int dp[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int res = INT_MIN;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int dp[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] += arr[i] + dp[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << dp[e] - dp[s - 1] << '\n';
	}

	return 0;
}
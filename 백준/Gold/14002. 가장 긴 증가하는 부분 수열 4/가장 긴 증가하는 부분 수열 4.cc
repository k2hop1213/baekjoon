#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001][1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[0][i] = 1;
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i]) {
				dp[0][i] = max(dp[0][j] + 1, dp[0][i]);
				if (dp[0][i] == dp[0][j] + 1) dp[1][i] = j;
			}
		}
	}
	int res = 0;
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[0][i]);
		if (res == dp[0][i]) idx = i;
	}
	cout << res << '\n';
	stack<int>s;
	while (1) {
		s.push(arr[idx]);
		idx = dp[1][idx];
		if (idx == 0) {
			break;
		}

	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[41];
int dp[41];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int m;
	cin >> m;
	if (m == 0) {
		cout << dp[n];
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		arr[temp] = -1;
	}

	

	int len = 0;
	int res = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != -1) {
			len++;
		}
		if (arr[i] != -1 && i == n) {

			res *= dp[len];

		}
		if(arr[i] == -1) {
			res *= dp[len];
			len = 0;
		}

	}

	cout << res;
	return 0;
}
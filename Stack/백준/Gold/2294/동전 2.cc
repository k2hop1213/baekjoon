#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int arr[101];

	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	int res = (dp[k] != 10001) ? dp[k] : -1;
	cout << res;

	return 0;
}
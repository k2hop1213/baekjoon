#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int arr[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;


	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k];

	return 0;
}
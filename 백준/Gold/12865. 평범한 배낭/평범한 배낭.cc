#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[101];
int dp[100001];// 그 무게에서의 가치합의 최대
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);

	int res = 0;



	for (int i = 0; i < n; i++) {
		for (int j = m; j >= arr[i].first; j--) {

			dp[j] = max(arr[i].second + dp[j - arr[i].first], dp[j]);
			
		}
	}

	cout << dp[m];

	return 0;
}
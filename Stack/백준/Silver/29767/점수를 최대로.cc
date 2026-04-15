#include <bits/stdc++.h>
using namespace std;

long long arr[300001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	sort(arr + 1, arr + n + 1);
	long long res = 0;
	for (int i = n; i >= n - m + 1; i--) {
		res += arr[i];
	}
	cout << res;



	return 0;
}
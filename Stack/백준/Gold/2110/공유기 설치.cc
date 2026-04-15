#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> arr[i];

	sort(arr, arr + n);

	int left = 1;
	int right = arr[n - 1] - arr[0];
	int res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int last_val = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] - last_val >= mid) {
				cnt++;
				last_val = arr[i];
			}

		}
		if (cnt >= m) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}
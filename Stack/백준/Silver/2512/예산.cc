#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	cin >> m;

	sort(arr, arr + n);

	int left = 1;
	int right = arr[n - 1];
	int res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) {
				sum += arr[i];
			}
			else sum += mid;
		}

		if (sum <= m) {
			res = max(res,mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}


	}
	cout << res;

	return 0;
}
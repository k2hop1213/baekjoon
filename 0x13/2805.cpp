#include <stdc++.h>
using namespace std;
long long arr[1000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];

	sort(arr, arr + n);

	long long left = 1;
	long long right = arr[n - 1];
	long long res = 0;
	while (left <= right) {
		long long cnt = 0;
		long long mid = (left + right) / 2;

		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid)continue;
			cnt += arr[i] - mid;
		}
		if (cnt >= m) {
			if (mid > res) {
				res = mid;
			}
			left = mid + 1;
			
		}
		else {
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}

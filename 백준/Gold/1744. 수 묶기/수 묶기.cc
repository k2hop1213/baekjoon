#include <bits/stdc++.h>
using namespace std;

int arr[51];
int vis[51];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());

	long long sum = 0;
	int left = 0;
	int right = n - 1;

	for (; left < n; left += 2) {
		if (left + 1 < n && arr[left] > 1 && arr[left + 1] > 1) {
			sum += (arr[left] * arr[left + 1]);
		}
		else {
			break;
		}
	}

	for (; right >= 0; right -= 2) {
		if (right - 1 >= 0 && arr[right] <= 0 && arr[right - 1] <= 0) {
			sum += (arr[right] * arr[right - 1]);
		}
		else {
			break;
		}
	}

	for (int i = left; i <= right; i++) {
		sum += arr[i];
	}

	cout << sum;

	return 0;
}
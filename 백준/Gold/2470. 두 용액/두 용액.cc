#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)cin >> arr[i];

	sort(arr, arr + n);

	int left = 0;
	int right = n - 1;
	long long min = LLONG_MAX;
	pair<long long, long long>res;
	while (left < right) {
		long long sum = arr[left] + arr[right];
		
		if (min > abs(sum)) {
			min = abs(sum);
			res = { arr[left],arr[right] };
		}

		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			break;
		}

	}

	cout << res.first << ' ' << res.second;


	return 0;
}
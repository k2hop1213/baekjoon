#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long m;

	cin >> n >> m;
	for(int i = 0; i < n; i++)cin >> arr[i];

	sort(arr, arr + n);

	int left = 0;
	int right = 0;
	long long num;
	long long res = LLONG_MAX;
	while (left < n && right < n) {
		num = arr[right] - arr[left];

		

		if (num >= m) {
			left++;
			res = min(res, num);
		}
		else {
			right++;
		}

	}

	cout << res;

	return 0;
}
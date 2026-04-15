#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	pair<int, int>arr[1001];
	pair<int, int>max_h = { 0,0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (max_h.second < arr[i].second) {
			max_h = { i,arr[i].second };
		}
	}

	int cur = 0;
	int res = 0;
	for (int i = 0; i <= max_h.first; i++) {
		if (arr[i].second > cur) {
			cur = arr[i].second;
		}
		if (i < max_h.first) {
			res += cur * (arr[i + 1].first - arr[i].first);
		}
	}

	cur = 0;
	for (int i = n - 1; i >= max_h.first; i--) {
		if (arr[i].second > cur) {
			cur = arr[i].second;
		}
		if (i > max_h.first) {
			res += cur * (arr[i].first - arr[i - 1].first);
		}

	}
	res += max_h.second;
	cout << res;

	return 0;
}
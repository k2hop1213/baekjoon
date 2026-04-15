#include <bits/stdc++.h>
using namespace std;

pair<int, int>arr[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i].second >> arr[i].first;

	sort(arr, arr + n);
	int count = 0;
	int last_end_time = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i].second >= last_end_time) {
			count++;
			last_end_time = arr[i].first;
		}
	}

	cout << count;
	
	return 0;
}
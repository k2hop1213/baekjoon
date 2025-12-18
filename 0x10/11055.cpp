#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int sum[1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)sum[i] = arr[i];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				sum[i] = max(sum[i], sum[j] + arr[i]);
			}
		}
	}
	int res = 0;

	for (int i = 0; i < n; i++) {
		res = max(res, sum[i]);
	}
	
	cout << res;

	return 0;
}

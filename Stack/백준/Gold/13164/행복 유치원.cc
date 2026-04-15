#include <bits/stdc++.h>
using namespace std;
int arr[300001];
int arr1[300001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) {
		arr1[i - 1] = arr[i] - arr[i - 1];


	}
	sort(arr1, arr1 + n - 1);
	int res = 0;

	for (int i = 0; i < n - m; i++) {
		res += arr1[i];
	}
	
	
	cout << res;

	return 0;
}
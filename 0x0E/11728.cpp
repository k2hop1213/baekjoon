#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int arr1[1000001];
int res[2000001];
int n, m;
int idx = 0;
int idx1 = 0;
void func() {

	if (idx == n) {
		for (int i = idx1; i < m; ++i) res[idx + i] = arr1[i];
		return;
	}

	if (idx1 == m) {
		for (int i = idx; i < n; ++i) res[idx1 + i] = arr[i];
		return;
	}

	if (arr[idx] < arr1[idx1]) {
		res[idx + idx1] = arr[idx];
		idx++;
		func();
	}
	else if (arr[idx] > arr1[idx1]) {
		res[idx + idx1] = arr1[idx1];
		idx1++;
		func();
	}
	else {
		res[idx + idx1] = arr[idx];
		idx++;
		res[idx + idx1] = arr1[idx1];
		idx1++;
		func();
	}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> arr1[i];

	func();
	for (int i = 0; i < n + m; i++) cout << res[i] << ' ';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int arr[2250001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];

	}
	sort(arr, arr + n * n);
	cout << arr[n * n - n];

	return 0;
}
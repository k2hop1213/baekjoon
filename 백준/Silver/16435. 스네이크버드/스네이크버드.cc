#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] <= m) {
			m++;
		}
	}
	cout << m;

	return 0;
}
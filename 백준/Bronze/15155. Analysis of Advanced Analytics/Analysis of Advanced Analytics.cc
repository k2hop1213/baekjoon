#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	int res = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			sum += arr[i];
			res++;
			continue;
		}
		if (sum + arr[i] <= m) {
			sum += arr[i];
		}
		else {
			sum = arr[i];
			res++;
		}
	}
	cout << res;

	return 0;
}
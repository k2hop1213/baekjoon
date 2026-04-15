#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];

	if (n == 1) {
		if (arr[0] <= 1440)cout << arr[0];
		else cout << -1;
		return 0;
	}

	sort(arr, arr + n);

	int idx1 = n - 2;
	int idx2 = n - 1;
	int res = 0;

	while (1) {
		if (arr[idx1] == 0 && arr[idx2] == 0) {
			break;
		}

		if(arr[idx1])arr[idx1]--;
		if(arr[idx2])arr[idx2]--;
		res++;
		sort(arr, arr + n);
	}

	if (res <= 1440)cout << res;
	else cout << -1;

	return 0;
}
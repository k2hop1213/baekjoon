#include <bits/stdc++.h>
using namespace std;

int arr[10000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (cin.eof())break;
		int m;
		cin >> m;
		if (m == 0) {
			cout << "danger\n";
			continue;
		}
		for (int i = 0; i < m; i++)cin >> arr[i];
		sort(arr, arr + m);

		int left = 0;
		int right = m - 1;
		pair<int, int>res;
		while (left < right) {
			int sum = arr[left] + arr[right];

			if (sum < (n * (int)pow(10, 7))) {
				left++;
			}
			else if (sum > (n * (int)pow(10, 7))) {
				right--;
			}
			else {
				res = { arr[left],arr[right] };
				break;
			}
		}

		if (left == right) cout << "danger\n";
		else cout << "yes " << res.first << ' ' << res.second << '\n';
	}
	return 0;
}
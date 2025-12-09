#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int num[10];
void func(int k) {
	if (k == m) {
		for (int i = 1; i < m; i++) {
			if (arr[i] < arr[i - 1]) {
				return;
			}
		}
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int last_val = 0;

	for (int i = 1; i <= n; i++) {
		if (num[i] == last_val) {
			continue;
		}

		arr[k] = num[i];

		last_val = num[i];

		func(k + 1);
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	sort(num + 1, num + n + 1);
	func(0);

	return 0;
}

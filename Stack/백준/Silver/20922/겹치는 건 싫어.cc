#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int vis[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s = 0;
	int e = 0;
	int res = 0;
	while (e < n) {

		if (vis[arr[e]] < m) {
			vis[arr[e]]++;
			e++;
			res = max(res, e - s);
		}
		else {
			vis[arr[s]]--;
			s++;
		}

	}

	cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
bool vis[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)cin >> arr[i];

	int s = 0;
	int e = 0;
	long long cnt = 0;
	for (s = 0; s < n; s++) {
		while (e < n && !vis[arr[e]]) {
			vis[arr[e]] = 1;
			e++;
;
		}

		cnt += (e - s);
		vis[arr[s]] = 0;
	}

	cout << cnt;

	return 0;
}
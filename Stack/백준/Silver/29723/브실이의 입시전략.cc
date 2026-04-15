#include <bits/stdc++.h>
using namespace std;
map<string, int>s;
int arr[10001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string t; int t1;
		cin >> t >> t1;
		s[t] = t1;
	}
	int res = 0;
	int res1 = 0;
	for (int i = 0; i < k; i++) {
		string t;
		cin >> t;
		res += s[t];
		s.erase(t);
	}
	res1 = res;
	int idx = 0;
	for (auto i : s) {
		arr[idx++] = i.second;
	}
	sort(arr, arr + idx);

	for (int i = 0; i < m - k; i++) {
		res += arr[idx - i - 1];
		res1 += arr[i];
	}

	cout << res1 << ' ' << res;


	return 0;
}
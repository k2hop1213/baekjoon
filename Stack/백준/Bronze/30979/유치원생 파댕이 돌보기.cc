#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		res += t;
	}
	if (res >= n)cout << "Padaeng_i Happy";
	else cout << "Padaeng_i Cry";

	return 0;
}
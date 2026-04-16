#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<>>Q;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			Q.push(a);
		}
		if (n == 1) {
			cout << 0;
			return 0;
		}

		long long res = 0;
		int s = Q.size() - 1;
		for (int i = 0; i < s; i++) {
			long long a = Q.top(); Q.pop();
			long long b = Q.top(); Q.pop();
			res += (a + b);
			Q.push(a + b);
		}
		cout << res << '\n';
	}

	return 0;
}
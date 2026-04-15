#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>>Q;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		Q.push(t);
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}

	long long res = 0;
	int s = Q.size() - 1;
	for (int i = 0; i < s; i++) {
		int a = Q.top(); Q.pop();
		int b = Q.top(); Q.pop();
		res += (a + b);
		Q.push(a + b);
	}
	cout << res;

	return 0;
}
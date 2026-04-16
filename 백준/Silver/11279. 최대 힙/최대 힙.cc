#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	priority_queue<int>Q;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t != 0)Q.push(t);
		else {
			if (Q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << Q.top() << '\n';
				Q.pop();
			}
		}
	}




	return 0;
}
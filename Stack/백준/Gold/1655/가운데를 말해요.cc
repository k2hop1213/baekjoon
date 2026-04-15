#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>>Q;
	priority_queue<int>Q1;
	int f;
	cin >> f;
	cout << f << '\n';
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;

		if (t < f) {
			Q.push(f);
			Q1.push(t);
		}
		else {
			Q.push(t);
			Q1.push(f);
		}

		if (i % 2 == 0) {
			f = Q.top(); Q.pop();
		}
		else {

			f = Q1.top(); Q1.pop();
		}
		cout << f << '\n';

	}



	return 0;
}
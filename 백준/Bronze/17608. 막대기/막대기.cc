#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.push(t);
	}

	int cnt = 1;
	int c = s.top();
	s.pop();
	while (!s.empty()) {
		if (s.top() > c) { 
			cnt++; 
			c = s.top();
		}
		s.pop();
	}

	cout << cnt;
	return 0;
}
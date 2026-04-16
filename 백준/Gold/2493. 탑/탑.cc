#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	stack<pair<int,int>>s;
	int m;//현재 최댓값
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (i == 1) {
			cout << 0 << ' ';
			m = t;
		}
		else {
			if (m > t) {
				
				while (!s.empty() && t >= s.top().second) {
					s.pop();
				}
				cout << s.top().first << ' ';

			}
			else {
				m = t;
				cout << 0 << ' ';
			}
		}

		s.push({ i,t });
	}
	

	return 0;
}
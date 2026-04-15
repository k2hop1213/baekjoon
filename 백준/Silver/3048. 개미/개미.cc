#include <bits/stdc++.h>
using namespace std;
int jump1[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1;
	string s2;

	int n, m;
	int t;
	cin >> n >> m;
	cin >> s1 >> s2;
	cin >> t;
	string res(n + m, ' ');
	queue<pair<int, int>>Q;
	for (int i = 0; i < n; i++) {
		jump1[i] = 1;
	}
	for (int i = 0; i < t; i++) {
		
		for (int j = 0; j < n + m - 1; j++) {
			if (jump1[j] == 1 && jump1[j + 1] == 0) {
				Q.push({ j,j + 1 });
			}
		}
		while (!Q.empty()) {
			pair<int, int>cur = Q.front(); Q.pop();
			swap(jump1[cur.first], jump1[cur.second]);

		}
		
	}
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < m + n; i++) {
		if (jump1[i]) {
			res[i] = s1[(n - 1) - idx1++];
		}
		else res[i] = s2[idx2++];
	}

	cout << res;

	return 0;
}
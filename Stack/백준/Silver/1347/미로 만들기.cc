#include <bits/stdc++.h>
using namespace std;
int vis[101][101];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	pair<int, int>cur = { 50,50 };

	int t = 0;
	vis[cur.first][cur.second] = 1;
	int max1 = cur.first; 
	int max2 = cur.second; 
	int min1 = cur.first; 
	int min2 = cur.second; 
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') {
			t = (t - 1 + 4) % 4;
		}

		if (s[i] == 'R') {
			t = (t + 1) % 4;
		}

		if (s[i] == 'F') {
			if (t == 0) cur.first++;
			else if (t == 1)cur.second--;
			else if (t == 2)cur.first--;
			else cur.second++;
			vis[cur.first][cur.second] = 1;
			max1 = max(max1, cur.first);
			max2 = max(max2, cur.second);
			min1 = min(min1, cur.first);
			min2 = min(min2, cur.second);
		}
		
	}

	for (int i = min1; i <= max1; i++) {
		for (int j = min2; j <= max2; j++) {
			if (vis[i][j]) cout << '.';
			else cout << '#';

		}
		cout << '\n';
	}

	return 0;
}
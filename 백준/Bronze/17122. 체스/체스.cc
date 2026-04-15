#include <bits/stdc++.h>
using namespace std;
int board[9][9];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (i % 2) {
				if (j % 2)board[i][j] = 1;
			}
			else {
				if (j % 2 == 0)board[i][j] = 1;
			}
		}
	}
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int t;
		cin >> t;
		int temp = 0;
		int res = 0;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				temp++;
				if (temp == t) {
					res = board[i][j];
				}
			}
		}
		if (res == board[s[1] - '0'][s[0] - 'A' + 1]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
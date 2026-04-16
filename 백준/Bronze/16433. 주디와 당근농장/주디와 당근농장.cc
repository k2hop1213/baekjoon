#include <bits/stdc++.h>
using namespace std;

string board[100];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		board[i] = string(n, '.');
	}
	int x, y;
	cin >> x >> y;

	board[x - 1][y - 1] = 'v';
	
	if (((x - 1) % 2 && (y - 1) % 2) || ((x - 1) % 2 == 0 && (y - 1) % 2 == 0)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i % 2 == 0){
					if (j % 2 == 0) board[i][j] = 'v';
				}
				else {
					if (j % 2)board[i][j] = 'v';
				}
			}
		}
	}
	else if ((x - 1) % 2 || (y - 1) % 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 2 == 0) {
					if (j % 2 ) board[i][j] = 'v';
				}
				else {
					if (j % 2 == 0)board[i][j] = 'v';
				}
			}
		}
	}
	for (int i = 0; i < n; i++)cout << board[i] << '\n';

	return 0;
}
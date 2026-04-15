#include <bits/stdc++.h>
using namespace std;

vector<string> board;
void func(int r, int c, int size) {


	if (size == 3) {

		board[r][c] = '*';

		board[r + 1][c - 1] = '*';
		board[r + 1][c + 1] = '*';

		for (int j = 0; j < 5; j++) {
			
			board[r + 2][c - 2 + j] = '*';
		}
		return;
	}
	int temp = 0;

	int size1 = size / 2;



	func(r, c, size1);

	func(r + size1, c - size1, size1);

	func(r + size1, c + size1, size1);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	board.assign(n, string(2 * n, ' '));

	func(0, n - 1, n);
	for (int i = 0; i < n; i++) {
		cout << board[i] << '\n';
	}

	return 0;
}
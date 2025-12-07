#include <stdc++.h>
using namespace std;

vector<string> board;

void func(int r, int c, int size) {

	if (size == 1) {
		board[r][c] = '*';
		return;
	}

	for (int i = 0; i < 4 * size - 3; i++) {
		for (int j = 0; j < 4 * size - 3; j++) {
			if (i == 0 || i == 4 * size - 4 || j == 0 || j == 4 * size - 4) {
				board[r + i][c + j] = '*';
			}

		}
	}
	int r1 = r + 2;
	int c1 = c + 2;
	int size1 = size - 1;
	func(r1, c1, size1);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	if (n == 1) { cout << '*'; return 0; }
	board.assign(4 * n - 3, string(4 * n - 3, ' '));
	func(0, 0, n);

	for (int i = 0; i < 4*n-3; i++) {
		cout << board[i] << '\n';
	}
	return 0;
}

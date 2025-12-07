#include <stdc++.h>
using namespace std;

vector<string> board;
void func(int r, int c, int size) {


	if (size == 1) {
		board[r][c] = '*';
		return;

	}
	int temp = 0;
	
	int size1 = size / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp++;
			if (temp != 5) {
				func(r + i * size1, c + j * size1, size1);
			}
		}
	}
	


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	board.assign(n, string(n, ' '));

	func(0, 0, n);
	for (int i = 0; i < n; i++) {
		cout << board[i] << '\n';
	}

	return 0;
}

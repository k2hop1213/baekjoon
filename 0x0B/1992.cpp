#include <stdc++.h>
using namespace std;

string board[64];
void func(int r, int c, int size) {

	int flag = 0;
	char temp = board[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (board[i][j] != temp) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0){
		cout << temp;

		return;
	}
	else {
		cout << '(';
		int size1 = size / 2;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(r + i * size1, c + j * size1, size1);
			}
		}
		cout << ')';
	}


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	func(0, 0, n);

	return 0;
}

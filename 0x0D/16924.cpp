#include <stdc++.h>
using namespace std;
int arr[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];

	if (n == 1) {
		if (arr[0] <= 1440)cout << arr[0];
		else cout << -1;
		return 0;
	}

	sort(arr, arr + n);

	int idx1 = n - 2;
	int idx2 = n - 1;
	int res = 0;

	while (1) {
		if (arr[idx1] == 0 && arr[idx2] == 0) {
			break;
		}

		if(arr[idx1])arr[idx1]--;
		if(arr[idx2])arr[idx2]--;
		res++;
		sort(arr, arr + n);
	}

	if (res <= 1440)cout << res;
	else cout << -1;

	return 0;
}
#endif
//16924
#if 0
#include <stdc++.h>
using namespace std;
string board[101];
bool vis[101][101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> board[i];

	int size = 1;

	vector<tuple<int, int, int>>arr;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '*') {
				if (i - size < 0 || j - size < 0 || i + size >= n || j + size >= m) continue;
				while (1) {
					if (i - size < 0 || j - size < 0 || i + size >= n || j + size >= m) break;
					if (board[i + size][j] == '*' && board[i - size][j] == '*' && board[i][j + size] == '*' && board[i][j - size] == '*') {
						arr.push_back({ i + 1, j + 1, size });
						vis[i][j] = 1;
						vis[i + size][j] = 1;
						vis[i - size][j] = 1;
						vis[i][j + size] = 1;
						vis[i][j - size] = 1;
						size++;
					}
					else break;
				}
				size = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && board[i][j] == '*') {
				cout << -1;
				return 0;
			}
		}
	}

	int res = arr.size();
	cout << res << '\n';

	for (auto a : arr) {
		cout << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << '\n';
	}


	return 0;
}

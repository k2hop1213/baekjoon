#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int sum[101][101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int t1;
			cin >> t1;
			sum[t1][1] = arr[t1][n];
			for (int j = 1; j <= n - 1; j++) {
				sum[t1][j + 1] = arr[t1][j];
			}
			for (int j = 1; j <= n; j++) {
				arr[t1][j] = sum[t1][j];
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					sum[k][n - j + 1] = arr[j][k];
				}
			}
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					arr[j][k] = sum[j][k];
				}
			}
		}

	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
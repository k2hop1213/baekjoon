#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			cout << ' ';
		}
		for (int j = n - i; j < n; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = 2; i <= n; i++) {
		for (int j = n - i + 1; j < n; j++) {
			cout << ' ';
		}
		for (int j = i - 1; j < n; j++) {
			cout << '*';
		}
		
		cout << '\n';
	}

	return 0;
}
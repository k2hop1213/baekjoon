#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cnt[0] = 0;
	cnt[1] = 1;
	if (n < 0) {
		n = -n;
		if (n % 2) cout << 1 << '\n';
		else cout << -1 << '\n';
	}
	else if (n > 0) cout << 1 << '\n';
	else { cout << 0 << '\n' << 0; return 0; }

	for (int i = 2; i <= n; i++) {
		cnt[i] = cnt[i - 1] + cnt[i - 2];
		cnt[i] %= 1000000000;
	}
	cout << cnt[n];

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long cnt[10000001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (cnt[temp]) {
			cout << cnt[temp] << '\n';
			continue;
		}
		for (int j = 4; j <= temp; j++) {
			cnt[j] = (cnt[j - 1] + cnt[j - 2] + cnt[j - 3]) % 1000000009;
		}
		cout << cnt[temp] << '\n';
	}



	return 0;
}
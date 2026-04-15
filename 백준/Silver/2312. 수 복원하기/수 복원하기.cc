#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
	if (n < 2)return 0;
	if (n == 2)return 1;
	if (n % 2 == 0)return 0;
	for (int i = 3; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int temp = n;
		if (isPrime(n)) {
			cout << n << ' ' << 1 << '\n';
			continue;
		}
		int flag = 0;
		int cnt = 0;
		for (int i = 2; i <= temp; i++) {
			if (isPrime(i) && n % i == 0) {
				while (n % i == 0) {
					n /= i;
					cnt++;
					if (isPrime(n)) {
						if (i == n) {
							cout << i << ' ' << cnt + 1 << '\n';
						}
						else {
							cout << i << ' ' << cnt << '\n';
							cout << n << ' ' << 1 << '\n';
							
						}
						flag = 1;
						break;
					}
				}
				if(!flag)cout << i << ' ' << cnt << '\n';
				cnt = 0;
			}
			if (flag) {
				break;
			}
		}
	}

	return 0;
}
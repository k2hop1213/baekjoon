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

	int n;
	cin >> n;
	int temp = n;
	if (isPrime(n)) {
		cout << n;
		return 0;
	}
	for (int i = 2; i <= temp; i++) {
		if (isPrime(i) && n % i == 0) {
			while (n % i == 0) {
				n /= i;
				cout << i << '\n';
				if (isPrime(n)) {
					cout << n;
					return 0;
				}
			}
		}
	}

	return 0;
}
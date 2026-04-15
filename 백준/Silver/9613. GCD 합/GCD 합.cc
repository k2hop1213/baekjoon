#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {

		int t;
		cin >> t;
		int arr[101];
		for (int i = 0; i < t; i++)cin >> arr[i];
		long long sum = 0;
		for (int i = 0; i < t - 1; i++) {
			for (int j = i + 1; j < t; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';

	}

	return 0;
}
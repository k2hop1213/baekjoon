#include <bits/stdc++.h>
using namespace std;
int arr[101];

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];

	for (int i = 1; i < n; i++) {
		if (arr[0] % arr[i] == 0) {
			cout << arr[0] / arr[i] << '/' << 1 << '\n';
		}
		else {
			cout << arr[0] / gcd(arr[0], arr[i]) << '/' << arr[i] / gcd(arr[0], arr[i]) << '\n';
		}
	}



	return 0;
}
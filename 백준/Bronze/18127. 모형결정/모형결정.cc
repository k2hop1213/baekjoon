#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	long long res = 1;
	long long temp = 0;
	for (int i = 1; i <= b; i++) {
		if (i == 1) {
			res += a - 1;
			temp = a - 1;
		}
		else {
			temp += a - 2;
			res += temp;
		}
	}

	cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;

	for (long long a = 0; a < m; a++) {
		long long c = (x1 - (a * seed) % m + m) % m;

		if ((a * x1 + c) % m == x2) {
			cout << a << " " << c ;
			return 0;
		}
	}


	return 0;
}
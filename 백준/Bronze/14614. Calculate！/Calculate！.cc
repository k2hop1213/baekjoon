#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	string c;
	cin >> a >> b >> c;
	int res = a ^ b;
	if ((c[c.length() - 1] - '0') % 2) {
		cout << res;
	}
	else cout << a;


	return 0;
}
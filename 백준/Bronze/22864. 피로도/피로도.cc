#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a > d) {
		cout << 0;
		return 0;
	}
	int cur = 0;
	int res = 0;
	for (int i = 1; i <= 24; i++) {
		if (i == 1) { 
			cur += a; 
			res += b;
			continue;
		}
		if (cur + a > d) {
			if (cur - c < 0) cur = 0;
			else cur -= c;
		}
		else {
			cur += a;
			res += b;
		}
	}
	cout << res;
	return 0;
}
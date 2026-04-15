#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		cout << "Pairs for " << t << ": ";
		for (int i = 1; i <= t / 2; i++) {
			if (i != t - i) { 
				if (i != 1)cout << ", " << i << ' ' << t - i;
				else cout << i << ' ' << t - i; 
			}
		}
		cout << '\n';

	}


	return 0;
}
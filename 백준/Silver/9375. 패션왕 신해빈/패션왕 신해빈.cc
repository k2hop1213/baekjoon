#include <bits/stdc++.h>
using namespace std;



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		map<string, int>m;
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			m[s2]++;
		}
		long long res = 1;

		for (auto i : m) {
			res *= (i.second + 1);
		}
		cout << res - 1 << '\n';

	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1;
	string s2;
	cin >> s1 >> s2;

	while (s1 != s2) {

		if (s2.back() == 'A') {
			s2.pop_back();
		}
		else {
			s2.pop_back();
			reverse(s2.begin(), s2.end());
		}
		if (s1.length() == s2.length()) {
			if (s1 != s2) {
				cout << 0;
				return 0;
			}
		}

	}
	cout << 1;
	return 0;
}
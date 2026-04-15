#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	if (s.length() == 3) {
		cout << s;
		return 0;
	}
	string s1 = "";
	string res = "";
	for (int i = 1; i < s.length() - 1; i++) {
		for (int j = i + 1; j < s.length(); j++) {
			s1 = s;
			reverse(s1.begin(), s1.begin() + i);
			reverse(s1.begin() + i, s1.begin() + j);
			reverse(s1.begin() + j, s1.end());
			if (res == "")res = s1;
			else res = min(res, s1);
		}
	}
	cout << res;
	return 0;
}
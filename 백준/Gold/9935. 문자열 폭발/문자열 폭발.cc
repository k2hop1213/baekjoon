#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string s1;
	cin >> s >> s1;

	string res = "";

	for (int i = 0; i < s.length(); i++) {
		res += s[i];
		int flag = 0;
		if (res.length() >= s1.length()) {
			for (int j = 0; j < s1.length(); j++) {
				if (res[res.length() - s1.length() + j] != s1[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				for (int j = 0; j < s1.length(); j++) {
					res.pop_back();
				}
			}

		}
	}
	if (res.empty()) {
		cout << "FRULA";
	}
	else {
		cout << res;
	}
	return 0;
}
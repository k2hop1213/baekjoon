#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int flag = 0;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		cout << s.length();
		return 0;
	}
	flag = 0;
	stack<char> S;
	string res = s;
	for (int i = 1; i < s.length(); i++) {
		res = s;
		flag = 0;
		for (int j = 0; j < i; j++) {
			S.push(s[j]);
		}
		while (!S.empty()) {
			res += S.top();
			S.pop();
		}

		for (int j = 0; j < res.length() / 2; j++) {
			if (res[j] != res[res.length() - 1 - j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << res.length();
			return 0;
		}
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int cnt = 0;
	int res = 0;
	while (1) {
		string temp;
		stack<char>s;
		cin >> temp;
		if (temp[0] == '-')return 0;

		cnt++;
		res = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '{') {
				s.push(temp[i]);
			}
			else {
				if(!s.empty()) s.pop();
				else {
					s.push('{');
					res++;
				}
			}
		}

		if (!s.empty()) {
			res += ((s.size() + 1) / 2);
		}

		cout << cnt << ". " << res << '\n';

	}

	return 0;
}
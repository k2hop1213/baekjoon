#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int c = 1;
	while (n--) {
		string s;
		stack<string>res;
		if (c == 1)	cin.ignore();
		getline(cin, s);

		int i = 0;
		while (1) {
			string temp;
			while (s[i] != ' ' && s[i] != 0) {
				temp.push_back(s[i]);
				i++;
			}
			res.push(temp);
			if (s[i] == 0) {
				break;
			}
			i++;
		}
		cout << "Case #" << c << ": ";
		while (!res.empty()) {
			cout << res.top() << ' ';
			res.pop();
		}
		cout << '\n';
		c++;
	}
	return 0;
}
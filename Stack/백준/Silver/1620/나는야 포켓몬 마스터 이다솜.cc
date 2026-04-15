#include <bits/stdc++.h>
using namespace std;

map<string, int>s;
string s1[100002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s1[i];
		s[s1[i]] = i;
	}

	while (m--) {
		string temp;
		cin >> temp;
		if (isdigit(temp[0])) {
			cout << s1[stoi(temp)] << '\n';

		}
		else cout << s[temp] << '\n';
	}

	return 0;
}
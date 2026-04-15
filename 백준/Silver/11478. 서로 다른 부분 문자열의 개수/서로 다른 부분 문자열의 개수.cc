#include <bits/stdc++.h>
using namespace std;
map<string, int>m;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.length();
	int cnt = 1;
	for (cnt = 1; cnt <= len; cnt++) {
		for (int j = 0; j <= len - cnt; j++) {
			string temp = s.substr(j, cnt);
			m[temp] = 1;

		}

	}
	cout << m.size();

	return 0;
}
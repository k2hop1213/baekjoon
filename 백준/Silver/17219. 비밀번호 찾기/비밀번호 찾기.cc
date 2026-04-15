#include <bits/stdc++.h>
using namespace std;
map<string, string>m;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		string addr,pw;
		cin >> addr >> pw;
		m[addr] = pw;

	}
	for (int i = 0; i < b; i++) {
		string res;
		cin >> res;
		cout << m[res] << '\n';
	}


	return 0;
}
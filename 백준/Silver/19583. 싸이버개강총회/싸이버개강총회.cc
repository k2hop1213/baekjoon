#include <bits/stdc++.h>
using namespace std;

map<string, int>m;

int func(string s) {
	int t = 1000;
	int r = 0;
	for (int i = 0; i < 5; i++) {
		if (i == 2)continue;
		r += (s[i] - '0') * t;
		t /= 10;
	}
	return r;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int t1 = func(s1);
	int t2 = func(s2);
	int t3 = func(s3);

	int cnt = 0;
	string time, name;

	while (cin >> time >> name) {

		
		int t = func(time);

		if (t <= t1) {
			m[name] = 1;
		}

		if (t >= t2 && t <= t3) {
			if (m.find(name) != m.end()) {
				cnt++;
				m.erase(name);
			}
		}


	}
	cout << cnt;


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string str;

	cin >> n;
	cin >> str;

	string s, s1, s2;;

	for (int i = 0; i < 100; i++) {
		if (i % 3 == 0) s.push_back('A');
		else if (i % 3 == 1) s.push_back('B');
		else s.push_back('C');

		if (i % 4 == 0 || i % 4 == 2) s1.push_back('B');
		else if (i % 4 == 1) s1.push_back('A');
		else s1.push_back('C');

		if (i % 6 == 0 || i % 6 == 1)s2.push_back('C');
		else if (i % 6 == 2 || i % 6 == 3)s2.push_back('A');
		else s2.push_back('B');
	}

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == s[i]) a++;
		if (str[i] == s1[i])b++;
		if (str[i] == s2[i])c++;
	}

	int res = max({ a,b,c });

	cout << res << '\n';

	if (res == a)cout << "Adrian\n";
	if (res == b)cout << "Bruno\n";
	if (res == c)cout << "Goran";
	

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

string s;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int cnt = 0;
	while (1) {
		string s1;
		int sum = 0;
		if (s.length() == 1) {
			if ((s[0] - '0') % 3 == 0) {
				cout << cnt << "\nYES";
			}
			else cout << cnt << "\nNO";
			return 0;
		}
		for (int i = 0; i < s.length(); i++) {
			sum += (s[i] - '0');
		}
		cnt++;
		while (sum > 0) {
			s1.push_back((sum % 10) + '0');
			sum /= 10;
		}
		reverse(s1.begin(), s1.end());
		s = s1;
	}



	return 0;
}
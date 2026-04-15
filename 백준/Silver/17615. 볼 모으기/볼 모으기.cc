#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	auto get_cnt = [&](string str, char color) {
		int cnt = 0;
		int len = str.length();
		for (int i = len - 1; i > 0; i--) {
			if (str[i] == color) {
				if (str[i] != str[i - 1]) { 
					cnt++;
					for (int j = i - 1; j > 0; j--) {
						if (str[j] == str[j - 1]) cnt++; 
						else { i = j; break; }
					}
				}
			}
		}
		return cnt;
		};

	int res1 = get_cnt(s, 'R');
	int res2 = get_cnt(s, 'B');

	
	reverse(s.begin(), s.end());

	int res3 = get_cnt(s, 'R');
	int res4 = get_cnt(s, 'B');

	cout << min({ res1, res2, res3, res4 });

	return 0;
}
#include <stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = 0, idx = 0;

	while (idx < s.length()) {
		n++; 
		string t = to_string(n);
		for (char c : t) {
			if (idx < s.length() && c == s[idx]) idx++;
		}
	}
	cout << n;
	return 0;
}

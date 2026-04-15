#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		multiset<int>m;

		while (t--) {
			char c;
			cin >> c;
			if (c == 'D') {
				int a;
				cin >> a;
				if (m.empty())continue;
				if (a == 1)m.erase(prev(m.end()));
				else m.erase(m.begin());
			}
			else {
				int a;
				cin >> a;
				m.insert(a);
			}




		}

		if (m.empty())cout << "EMPTY\n";
		else {
			cout << *prev(m.end()) << ' ' << *m.begin() << '\n';
		}


	}
	return 0;
}
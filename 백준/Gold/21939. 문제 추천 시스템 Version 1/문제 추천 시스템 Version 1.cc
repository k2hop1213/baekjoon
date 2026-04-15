#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	multiset<pair<int, int>>m;

	int n, n1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int P, L;
		cin >> L >> P;
		m.insert({ P,L });
		arr[L] = P;
	}
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		string s;
		int temp,temp1;
		cin >> s;

		if (s == "recommend") {
			cin >> temp;
			if (temp == 1) {
				cout << prev(m.end())->second << '\n';
			}
			else {
				cout << m.begin()->second << '\n';
			}
		}
		else if (s == "add") {
			cin >> temp >> temp1;
			m.insert({ temp1,temp });
		}
		else {
			cin >> temp;
			int t = arr[temp];
			m.erase({ t,temp });

		}

	}

	return 0;
}
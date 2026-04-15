#include <bits/stdc++.h>
using namespace std;

map<string, string>m;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a;
	cin >> n >> a;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			string temp1;
			cin >> temp1;
			
			m[temp1] = temp;
		}
	}

	for (int i = 0; i < a; i++) {
		string temp; int num;
		cin >> temp >> num;
		if (num == 1) {
			auto t = m.find(temp);
			cout << t->second << '\n';
		}
		else {
			for (auto t : m) {
				if (t.second == temp) {
					cout << t.first << '\n';
				}

			}
		}

	}

	return 0;
}
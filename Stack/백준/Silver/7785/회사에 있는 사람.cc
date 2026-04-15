#include <bits/stdc++.h>
using namespace std;

set<string>s;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string name, log;
		cin >> name >> log;
		if (log == "enter")s.insert(name);
		else s.erase(name);


	}

	vector<string>res(s.begin(), s.end());
	sort(res.begin(), res.end(), greater<string>());
	for (auto i : res)cout << i << '\n';

	return 0;
}
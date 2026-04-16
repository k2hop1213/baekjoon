#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	list<int> res;
	cout << "<";
	
	for (int i = 1; i <= n; i++) {
		res.push_back(i);
	}
	auto t = res.begin();
	while (!res.empty()) {

		for (int j = 0; j < k - 1; j++) {
			t++;
			if (t == res.end()) {
				t = res.begin();
			}
		}

		if (res.size() == 1) {
			cout << *t;
		}
		else {
			cout << *t << ", ";
		}
		t = res.erase(t);
		if (t == res.end() && !res.empty()) {
			t = res.begin();
		}
	}
	cout << ">";

	return 0;
}
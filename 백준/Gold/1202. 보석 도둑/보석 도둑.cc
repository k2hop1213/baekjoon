#include <bits/stdc++.h>
using namespace std;;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, int>m;
	vector<pair<int, int>>v;
	int n, k;
	cin >> n >> k;
	int temp = n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
		
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());


	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		m[a]++;
	}

	long long res = 0;

	for (int i = 0; i < temp; i++) {
		if (m.empty())break;

		int a = v[i].first;
		int b = v[i].second;

		auto t = m.lower_bound(b);

		if (t != m.end()) {

			res += a;

			if (t->second == 1)m.erase(t);
			else t->second--;
		}


	}

	cout << res;


	return 0;
}
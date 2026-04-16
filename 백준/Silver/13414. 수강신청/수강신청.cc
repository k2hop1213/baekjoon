#include <bits/stdc++.h>
using namespace std;

map<string, int>s;
string s1[500005];
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> s1[i];
		int temp = s.count(s1[i]);
		if (temp) {
			s.erase(s1[i]);
			s[s1[i]] = i + 1;
		}
		else s[s1[i]] = i + 1;
	}
	
	vector<pair<string, int>>v(s.begin(), s.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0;  i < n && i < v.size(); i++) {

		cout << v[i].first << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {

	return a.second < b.second;
}

pair<int, string>arr[301];
bool vis[301];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int size = n / m;
	if (n % m) size++;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int idx = 0;
	int cnt = 0;
	while(cnt < n){
		
		while (idx < n && vis[idx]) {
			idx++;
		}
		if (idx == n) {
			break;
		}
		vector<pair<int, string>> temp;
		int a = arr[idx].first;
		for (int j = 0 ; j < n; j++) {
			if (abs(arr[j].first - a) <= 10 && vis[j] == 0 && temp.size() < m) {
				temp.push_back({ arr[j].first,arr[j].second });
				vis[j] = 1;
			}
			
		}
		if (temp.size() == m) {
			cout << "Started!" << '\n';
		}
		else {
			cout << "Waiting!" << '\n';
			
		}
		sort(temp.begin(), temp.end(), compare);

		for (const auto& b : temp) {
			cout << b.first << ' ' << b.second << '\n';
			cnt++;
		}
	}
	

	return 0;
}

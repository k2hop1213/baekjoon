#include <bits/stdc++.h>
using namespace std;
int arr[1001];

void func(int s, int e) {
	while (s < e) {
		swap(arr[s], arr[e]);
		s++;
		e--;
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	vector<pair<int, int>>s;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == i) continue;
		for (int j = i + 1; j <= n; j++) {
			if (i == arr[j]) {
				func(i, j);
				res++;
				s.push_back({ i,j });
			}
		}
	}

	cout << res << '\n';
	if (res != 0) {
		for (auto p : s) {
			cout << p.first << " " << p.second << '\n';
		}
	}

	return 0;
}
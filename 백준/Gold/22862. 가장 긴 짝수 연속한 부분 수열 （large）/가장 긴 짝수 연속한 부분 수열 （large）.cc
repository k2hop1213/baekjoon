#include <bits/stdc++.h>
using namespace std;

vector<int>arr;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	
	int s = 0;
	int e = 0;
	int res = 0;
	int cnt = 0;
	for (s = 0; s < n; s++) {
		
		if (arr[s] % 2) {
			cnt++;
		}

		while (cnt > m) {
			if (arr[e] % 2) {
				cnt--;
			}
			e++;
		}

		res = max(res, (s - e + 1) - cnt);
	}

	cout << res;


	return 0;
}
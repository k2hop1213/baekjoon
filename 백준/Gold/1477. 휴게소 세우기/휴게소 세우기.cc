#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int>dis;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, len;
	cin >> n >> m >> len;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	
	arr.push_back(0);
	arr.push_back(len);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 1; i++) {
		dis.push_back(arr[i + 1] - arr[i]);
	}
	int s = 1;
	int e = len - 1;

	int res = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < dis.size(); i++) {
			if (dis[i] > mid) {
				cnt += (dis[i] - 1) / mid;
			}
		}
		if (cnt <= m) {
			res = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}

	cout << res;


	return 0;
}
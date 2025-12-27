#include <stdc++.h>
using namespace std;

vector<int> arr[101];
vector<int> temp[101];
vector<int> bound[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			arr[i].push_back(t);
			temp[i].push_back(t);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
		arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bound[i].push_back(lower_bound(arr[i].begin(), arr[i].end(), temp[i][j]) - arr[i].begin());
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (equal(bound[i].begin(), bound[i].end(), bound[j].begin())) cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

#include <stdc++.h>
using namespace std;

int arr[500001];
int arr1[500001];
vector<int> v;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < m; i++)cin >> arr1[i];
	sort(arr1, arr1 + m);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (!binary_search(arr1, arr1 + m, arr[i])) {
			v.push_back(arr[i]);
			flag = 1;
		}
	}
	if (flag == 0)cout << 0;
	else {
		cout << v.size() << '\n';
		sort(v.begin(), v.end());
		for (auto a : v) {
			cout << a << ' ';
		}
	}

	return 0;
}

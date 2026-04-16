#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> res;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	arr.resize(n);
	res.resize(n);
	for (int i = 0; i < n; i++)cin >> arr[i];

	res.push_back(arr[0]);
	int size = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > res[res.size() - 1]) {
			res.push_back(arr[i]);
			size++;
		}
		else { 
			int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[idx] = arr[i];

		}
	}
	cout << size;


	return 0;
}
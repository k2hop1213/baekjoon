#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(1000001, 0);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp <= 1000000) v[temp]++;
	}
	int x;
	cin >> x;
	int res = 0;
	for (int i = 1; i < (x + 1) / 2; i++) {

		if (x - i <= 1000000) {
			if (v[i] && v[x - i]) {
				res++;
			}
		}

	}

	cout << res;
	return 0;
}

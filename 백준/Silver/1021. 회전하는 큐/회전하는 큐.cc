#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int>d;
	for (int i = 1; i <= n; i++)d.push_back(i);
	int m;
	cin >> m;
	int res = 0;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;

		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (d[i] == t) {
				idx = i;
				break;
			}
		}

		while (1) {
			if (d.front() == t) {
				d.pop_front();
				break;
			}
			if (idx <= d.size()/2) {
				int temp = d.front();
				d.push_back(temp);
				d.pop_front();
				res++;
			}
			else {
				int temp = d.back();
				d.push_front(temp);
				d.pop_back();
				res++;
			}
		}

	}

	cout << res;


	return 0;
}
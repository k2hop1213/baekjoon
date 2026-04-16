#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	deque<pair<int, int>>d;
	for (int i = 0; i < N; i++) {
		pair<int, int>t;
		cin >> t.first;
		t.second = i;
		while (!d.empty() && d.back().first >= t.first) d.pop_back();
		d.push_back(t);
		if (d.front().second <= (i - L)) d.pop_front();
		cout << d.front().first << " ";
	}



	return 0;
}
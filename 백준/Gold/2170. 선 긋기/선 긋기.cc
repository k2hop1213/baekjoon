#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<long long, long long>>board;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		board.push_back({ x,y });
	}

	sort(board.begin(), board.end());

	long long sum = 0;
	long long start = board[0].first;
	long long end = board[0].second;
	sum += end - start;
	for (int i = 1; i < board.size(); i++) {
		pair<long long, long long> cur = board[i];
		if (cur.second <= end) continue;
		else if (cur.first <= end) {
			sum += cur.second - end;
			end = cur.second;
		}
		else if (cur.first > end) {
			sum += cur.second - cur.first;
			end = cur.second;
		}
		
	}

	cout << sum;

	return 0;
}
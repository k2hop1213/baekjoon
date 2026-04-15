#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>>s;
	int m;//현재 최댓값
	long long res = 0;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (s.empty()) {

			s.push({ t,1 });
		}
		else {

			while (!s.empty() && t > s.top().first) {
				res += s.top().second;
				s.pop();
			}
			if (s.empty()) {
				s.push({ t,1 });
				continue;
			}
			
			if (t == s.top().first) {
				cnt = s.top().second;
				res += cnt;
				s.pop();
				if (!s.empty())res++;
				s.push({ t,cnt + 1 });
			}
			else {
				res++;
				s.push({ t,1 });
			}
		}
	}

	cout << res;

	return 0;
}
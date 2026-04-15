#include <bits/stdc++.h>
using namespace std;
int dist[100002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);

	while (dist[m] == -1) {
		int cur = Q.front(); Q.pop();
		for (int i : {cur - 1, cur + 1, cur * 2}) {
			if (i < 0 || i > 100000)continue;
			if (dist[i] != -1) continue;
			dist[i] = dist[cur] + 1;
			Q.push(i);
		}
	}
	cout << dist[m];


	return 0;
}
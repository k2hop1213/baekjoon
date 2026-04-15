#include <bits/stdc++.h>
using namespace std;
int dis[100001];
int vis[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "0\n1";
		return 0;
	}
	queue<int>Q;
	fill(dis, dis + 100001, -1);
	dis[a] = 0;
	vis[a] = 1;
	Q.push({ a });
	int dist = 0;
	int cnt = 0;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (dist && dis[cur] > dist)break;
		for (int i : {cur * 2, cur - 1, cur + 1}) {
			if (i < 0 || i > 100000)continue;
			if (dis[i] == -1) { 
				dis[i] = dis[cur] + 1;
				Q.push(i);
				vis[i] = vis[cur];
			}
			else if (dis[i] == dis[cur] + 1) {
				vis[i] += vis[cur];
			}
			
		}
	}
	cout << dis[b] << '\n' << vis[b];



	return 0;
}
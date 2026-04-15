#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis[1001];
int n, m, st;
int bfs() {
	queue<int> q;
	q.push(st);
	vis[st] = true;
	int res = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			res++;
		}
	}
	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	st = 1;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << bfs();


	return 0;
}
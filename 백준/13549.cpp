#include <stdc++.h>
using namespace std;
int dis[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	queue<int>Q;
	fill(dis, dis + 100001, -1);
	dis[a] = 0;
	Q.push({ a });
	while (dis[b] == -1) {
		int cur = Q.front(); Q.pop();
		for (int i : {cur * 2, cur - 1, cur + 1}) {
			if (i < 0 || i > 100000)continue;
			if (dis[i] != -1) continue;
			if (i == cur * 2) dis[i] = dis[cur];
			else dis[i] = dis[cur] + 1;
			Q.push(i);
		}
	}
	cout << dis[b];



	return 0;
}
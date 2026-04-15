#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	int x1, y1, dx, dy;
	cin >> x1 >> y1 >> dx >> dy;
	int t = max(dx, dy);
	for (int i = 2; i <= t ; i++) {
		if (dx % i == 0 && dy % i == 0) {
			dx /= i;
			dy /= i;
		}
	}

	int res1 = x1;
	int res2 = y1;
	int min = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
	while (1) {
		

		x1 += dx;
		y1 += dy;
		int dis = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
		if (dis < min) {
			min = dis;
			res1 = x1;
			res2 = y1;
		}
		else {
			break;
		}
	}
	cout << res1 << ' ' << res2;

	return 0;
}
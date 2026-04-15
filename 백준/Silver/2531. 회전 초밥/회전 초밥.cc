#include <bits/stdc++.h>
using namespace std;

int arr[30001];
int check[3001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < a; i++)cin >> arr[i];


	int s = 0;
	int e = 0;
	int res = 0;
	int cnt = 0;
	for (e = 0; e < c; e++) {
		if (check[arr[e]] == 0) cnt++;
		check[arr[e]]++;
	}
	for (s = 0; s < a; s++) {

		int temp = (check[d] == 0) ? 1 : 0;
		res = max(res, cnt + temp);

		check[arr[s]]--;
		if (check[arr[s]] == 0) cnt--;

		if (check[arr[e % a]] == 0) cnt++;
		check[arr[e % a]]++;
		e++;
	}

	cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[50001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
		tot += arr[i];
	}

	int s = 0;
	int e = 0;
	int res = 0;
	int sum = 0;
	while (s < n) {

		while (sum + arr[e % n] <= tot / 2) {
			sum += arr[e % n];
			e++;
			res = max(res, sum);
		}

		res = max(res, min(sum + arr[e % n], tot - (sum + arr[e % n])));

		sum -= arr[s];
		s++;

	}

	cout << res;

	return 0;
}
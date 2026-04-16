#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> arr[i];


	int idx = 0;
	int idx1 = 0;
	long long sum = arr[0];
	int res = n + 1;
	for (idx = 0; idx < n; idx++) {

		while (sum < m && idx1 < n) {
			
			idx1++;
            if(idx1 != n)sum += arr[idx1];
		}
		if (idx1 == n) { 
			break; 
		}

		res = min(res, idx1 - idx + 1);

		sum -= arr[idx];
	}

	if (res == n + 1)cout << 0;
    else cout << res;

	return 0;
}
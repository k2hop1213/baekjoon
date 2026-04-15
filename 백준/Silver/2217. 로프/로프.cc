#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int res = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		
		res = arr[i] * (n - i);
		if (i == 0) { 
			last = res;
			continue; 
		}
		res = max(res, last);
		last = res;

	}
	cout << res;

	return 0;
}
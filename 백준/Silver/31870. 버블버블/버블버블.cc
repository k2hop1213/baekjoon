#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	
	int cnt = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				cnt++;
			}
		}
	}
	
	reverse(arr, arr + n);

	int cnt1 = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				cnt1++;
			}
		}
	}

	cout << min(cnt, cnt1);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int len[1001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> arr[i]; 
		len[i] = 1;
	}

	int res = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				len[i] = max(len[i], len[j] + 1);
				res = max(res, len[i]);
			}
		}
	}
	cout << res;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[10001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {

		fill(arr, arr + 10001, 0);
		int a;
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + a);
		int m1 = 0;
		for (int i = 2; i < a; i++) {
			m1 = max(m1, arr[i] - arr[i - 2]);
		}

		
		cout << m1 << '\n';
	}


	return 0;
}
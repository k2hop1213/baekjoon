#include <stdc++.h>
using namespace std;
int arr[10001];
int sum[10001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> arr[i];
	}
	
	sum[0] = arr[0];
	if (n > 1) sum[1] = arr[0] + arr[1];
	if (n > 2) sum[2] = max({ arr[0] + arr[1], arr[0] + arr[2], arr[1] + arr[2] });

	for (int i = 3; i < n; i++) {
		sum[i] = max({ sum[i - 1], sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i] });
	}

	cout << sum[n - 1];


	return 0;
}

#include <stdc++.h>
using namespace std;
long long arr[10001];
long long sum[10001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);

	long long res = 0;
	for (int i = 1; i < n;  i++) {
		sum[i - 1] = arr[i] - arr[i - 1];
	}
	sort(sum, sum + n - 1, greater<int>());
	for (int i = k - 1; i < n - 1; i++) {
		res += sum[i];
	}
	cout << res;
	return 0;
}

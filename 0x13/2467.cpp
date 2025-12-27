#include <stdc++.h>
using namespace std;
long long arr[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);

	long long left = 0;
	long long right = n - 1;
	long long res = LLONG_MAX;
	pair<long long, long long> num;
	while (left < right) {
		long long sum = arr[left] + arr[right];
		if (abs(res) > abs(sum)) {
			res = sum;
			num = { arr[left],arr[right] };
		}
		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else break;
	}

	cout << num.first << ' ' << num.second;

	return 0;
}

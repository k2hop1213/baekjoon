#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		arr.push_back(t);
	}

	sort(arr.begin(), arr.end());


	long long num[3];
	long long res = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		int left = i + 1;
		int right = n - 1;
		while (left < right) {
			long long sum = arr[i] + arr[left] + arr[right];
			if (abs(res) > abs(sum)) {
				res = sum;
				num[0] = arr[i]; num[1] = arr[left]; num[2] = arr[right];
			}
			if (sum < 0) {
				left++;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				if (arr[left] == arr[right]) {
					
					break;
				}
				while (left + 1 < right && arr[left] == arr[left + 1]) left++; 
				while (right - 1 > left && arr[right] == arr[right - 1]) right--; 
				left++; right--;
			}
			
		}
	}
	sort(num, num + 3);

	for (int i = 0; i < 3; i++)cout << num[i] << ' ';
	return 0;
}
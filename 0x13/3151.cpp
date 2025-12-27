#include <stdc++.h>
using namespace std;

vector<int> arr;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { 
		int t;
		cin >> t;
		arr.push_back(t);
	}

	sort(arr.begin(), arr.end());


	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		int left = i + 1;
		int right = n - 1;
		while (left < right) {
			int sum = arr[i] + arr[left] + arr[right];
			
			if (sum < 0) {
				left++;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				if (arr[left] == arr[right]) {
					int m = right - left + 1;
					cnt += m * (m - 1) / 2;
					break;
				}
				int l_cnt = 1, r_cnt = 1;
				while (left + 1 < right && arr[left] == arr[left + 1]) { l_cnt++; left++; }
				while (right - 1 > left && arr[right] == arr[right - 1]) { r_cnt++; right--; }
				cnt += l_cnt * r_cnt;
				left++; right--;
			}

		}
	}
	cout << cnt;
	return 0;
}

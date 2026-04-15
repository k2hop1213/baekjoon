#include <bits/stdc++.h>
using namespace std;

long long arr1[1001];
long long arr2[1001];
vector<long long> sum1;
vector<long long> sum2;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) { 
		cin >> arr1[i];
	
	}
	int y;
	cin >> y;
	for (int i = 0; i < y; i++) { 
		cin >> arr2[i];
	}

	for (int i = 0; i < x; i++) {
		long long cur = 0;
		for (int j = i; j < x; j++) {
			cur += arr1[j];
			sum1.push_back(cur);
		}
	}

	for (int i = 0; i < y; i++) {
		long long cur = 0;
		for (int j = i; j < y; j++) {
			cur += arr2[j];
			sum2.push_back(cur);
		}
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());

	

	long long cnt = 0;
	int left = 0;                   
	int right = sum2.size() - 1;   

	while (left < sum1.size() && right >= 0) {
		long long sum = sum1[left] + sum2[right];

		if (sum == n) {
			long long t1 = sum1[left];
			long long cnt1 = 0;
			while (left < sum1.size() && sum1[left] == t1) {
				cnt1++;
				left++;
			}

			long long t2 = sum2[right];
			long long cnt2 = 0;
			while (right >= 0 && sum2[right] == t2) {
				cnt2++;
				right--;
			}
			cnt += (cnt1 * cnt2);
		}
		else if (sum < n) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << cnt;


	return 0;
}
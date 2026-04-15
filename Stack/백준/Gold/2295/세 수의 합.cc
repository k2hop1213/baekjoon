#include <bits/stdc++.h>
using namespace std;
long long num[1001];
vector<long long>sum;
vector<long long>res;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> num[i];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum.push_back(num[i] + num[j]);
		}
	}
	sort(sum.begin(), sum.end());
	sort(num, num + n);
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(sum.begin(), sum.end(), num[i] - num[j])) {
				cout << num[i];
				return 0;
			}
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int isPrime(int num) {
	if (num < 2) {

		return 0;
	}
	if (num == 2) {
		return 1;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}

	}

	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
        vector<int>arr;
		int temp = b;
		if (b == 1) {
			cout << a << ' ' << b << " NO\n";
			continue;
		}
		else if (!isPrime(b)) {
			cout << a << ' ' << b << " NO\n";
			continue;
		}
		int sum = 0;
		int flag = 0;
		while (1) {
			sum = 0;
			while (temp > 0) {
				sum += (temp % 10) * (temp % 10);
				temp /= 10;
			}
			temp = sum;
			if (sum == 1) {
				break;
			}
			if (!arr.empty()) {
				for (auto c : arr) {
					if (c == sum) {
						cout << a << ' ' << b << " NO\n";
						flag = 1;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			arr.push_back(sum);
		}

		if(flag == 0) cout << a << ' ' << b << " YES\n";

	}

	return 0;
}
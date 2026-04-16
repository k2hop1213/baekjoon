#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	int min = 99;
	int flag = 0;
	for (int i = 0; i < 7; i++) {
		int temp;
		cin >> temp;
		if (temp % 2) { 
			sum += temp;
			if (min > temp)min = temp;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << -1;
		return 0;
	}
	cout << sum << "\n" << min;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long int a, b;

	cin >> a >> b;
	if (a == b) {
		cout << "0";
		return 0;
	}
	cout << (int)abs(b - a) - 1<<"\n";
	long long int big = (a > b) ? a : b;
	long long int small = (a < b) ? a : b;
	for (long long int i = small + 1; i < big; i++) {
		cout << i << " ";
	}

	return 0;
}
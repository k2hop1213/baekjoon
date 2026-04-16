#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	if (n == 0) {
		cout << "NO" << endl;
		return 0;
	}

	vector<long long> fact;
	long long f = 1;
	fact.push_back(f); 
	for (int i = 1; i <= 20; ++i) {
		f *= i;
		if (f > 1000000000000000000LL) break;
		fact.push_back(f);
	}

	for (int i = fact.size() - 1; i >= 0; --i) {
		if (n >= fact[i]) {
			n -= fact[i];
		}
	}

	if (n == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
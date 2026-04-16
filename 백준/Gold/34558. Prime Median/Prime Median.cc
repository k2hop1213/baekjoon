#include <bits/stdc++.h>
using namespace std;

vector<bool> state(10000001, true);
vector<int> primes;
void sieve(int n) {
	state[1] = false;
	for (int i = 2; i <= n; i++) { 
		if (state[i]) {
			primes.push_back(i); 
			if (1LL * i * i <= n) {
				for (int j = i * i; j <= n; j += i)
					state[j] = false;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	sieve(1000001);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		auto it_s = lower_bound(primes.begin(), primes.end(), a);
		auto it_e = upper_bound(primes.begin(), primes.end(), b);

		if (it_s >= it_e) {
			cout << -1 << '\n';
			continue;
		}

		int s = it_s - primes.begin();
		int e = prev(it_e) - primes.begin();

		int dis = e - s + 1;

		if (dis % 2 == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << primes[(s + e) / 2] << '\n';
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<bool> state(4000001, true);
void sieve(int n) {
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i)
			state[j] = false;
	}
}
int arr[1000001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	sieve(n);
	int idx = 0;
	for (int i = 2; i < n; i++) {
		if (state[i]) {
			arr[idx++] = i;
		}
	}
	

	int s = 0;
	int e = 0;

	int cnt = 0;
	int sum = arr[0];
	if (state[n]) cnt++;
	for (e = 0; e < idx - 1; e++) {

		while (s < idx - 1 && sum < n) {
			s++;
			if(s != idx)sum += arr[s];
		}
		if (sum == n) {
			cnt++;
		}
		if (s == idx) { 
			
			break; 
		
		}
		

		sum -= arr[e];

	}
	cout << cnt;

	return 0;
}
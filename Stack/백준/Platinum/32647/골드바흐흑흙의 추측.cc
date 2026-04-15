#include <bits/stdc++.h>

using namespace std;

vector<long long> prime;

int isPrime(long long n) {
	if (n < 2) return 0;
	if (n != 2 && n % 2 == 0) return 0;
	if (n == 2) return 1;
	for (long long i = 3; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	for (long long i = a; i <= b; i++) {
		if (isPrime(i)) prime.push_back(i);
	}

	// 20억 칸짜리 배열 대신, 실제로 만들어지는 '합'만 저장하는 map을 씁니다.
	// map<만들어진 합, 경우의 수>
	map<long long, long long> dp;
	dp[0] = 1;

	for (long long p : prime) {
		// 뒤에서부터 갱신해야 중복을 피하므로 reverse iterator 사용
		// 또는 새로운 임시 map에 저장한 뒤 합치는 방식을 씁니다.
		map<long long, long long> next_dp = dp;
		for (auto const& i : dp) {
			long long next_sum = i.first + p;
			if (next_sum <= c) { // 목표값 c를 넘지 않을 때만 저장
				next_dp[next_sum] += i.second;
			}
		}
		dp = next_dp;
	}

	cout << dp[c]; // 맵에 c가 없으면 자동으로 0 출력

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long int func(long long int a, long long int b, long long int c) {
	
	if (b == 1) return a % c;
	long long int n = func(a, b / 2, c);
	n = n * n % c;
	if (b % 2 == 0)return n;
	return n * a % c;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long int a, b, c;
	cin >> a >> b >> c;

	cout << func(a, b, c);


	return 0;
}
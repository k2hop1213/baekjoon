#include <bits/stdc++.h>
using namespace std;

long long func(long long A, long long X, long long M) {

	if (X == 1)return A % M;
	long long n = func(A, X / 2, M);
	n = n * n % M;
	if (X % 2 == 0)return n;
	else return (n * (A % M)) % M;

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, X;
	cin >> A >> X;
	cout << func(A % 1000000007, X, 1000000007);

	return 0;
}
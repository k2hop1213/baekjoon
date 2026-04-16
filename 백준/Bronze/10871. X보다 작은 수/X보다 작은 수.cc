#include <bits/stdc++.h>
using namespace std;
/*
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
*/
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		if (temp < x) cout << temp << " ";
	}


	return 0;
}
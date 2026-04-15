#include <bits/stdc++.h>
using namespace std;

int arr[15];
bool isused[15];
string s;
int n;
string mx = "";
string mn = "";
void func(int k) {
	if (k > 1) {
		if (s[k - 2] == '<') {
			if (arr[k - 2] > arr[k - 1]) return;
		}
		else {
			if (arr[k - 2] < arr[k - 1]) return;
		}
	}

	if (k == n + 1) {
		string temp = "";
		for (int i = 0; i <= n; i++) temp += (char)(arr[i] + '0');

		if (mn == "") mn = temp; 
		mx = temp;             
		return;
	}

	for (int i = 0; i <= 9; i++) { 
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s += c;
	}

	func(0);

	cout << mx << '\n' << mn;

	return 0;
}
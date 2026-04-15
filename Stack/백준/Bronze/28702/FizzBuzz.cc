#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s[3];
	for (int i = 0; i < 3; i++)cin >> s[i];

	int num = 0;
	int flag = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i][0] >= '0' && s[i][0] <= '9') {
			num = stoi(s[i]);
			flag = 1;
		}
		else if (flag) {
			num++;
		}
	}
	num++;
	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0 && num % 5 != 0) {
		cout << "Fizz";
	}
	else if (num % 3 != 0 && num % 5 == 0) {
		cout << "Buzz";
	}
	else cout << num;


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int num = 1;
	int idx = 0;
	string res = "";
	int flag = 0;
	while (1) {

		if (!s.empty()) {

		}
		else {
			s.push(num);
			num++;
            res += '+';
		}
		if (s.top() != arr[idx]) {
			s.push(num);
			num++;
			res += '+';
		}
		else {
			s.pop();
			idx++;
			res += '-';
		}

		if (num > n) {
			
			
			while (!s.empty()) {
				if (s.top() != arr[idx]) {
					flag = 1;
					break;
				}
				s.pop();
				res += '-';
				idx++;
			}
			break;
		}


	}

	if (flag)cout << "NO";
	else {
		for (auto i : res) {
			cout << i << '\n';
		}

	}

	return 0;
}
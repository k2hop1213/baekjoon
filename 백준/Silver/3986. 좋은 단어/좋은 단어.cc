#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		stack<char> a;
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length();j++) {
			if (a.empty()) {
				a.push(temp[j]);
				continue;
			}
			if (a.top() == temp[j]) {
				a.pop();
			}
			else {
				a.push(temp[j]);
			}
		}
		if (a.empty()) {
			res++;
		}
	
	}
	cout << res;

	return 0;
}
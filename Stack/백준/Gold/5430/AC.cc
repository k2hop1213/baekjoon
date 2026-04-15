#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s1;
		cin >> s1;
		int n;
		cin >> n;
		string s2;
		cin >> s2;
		deque<int>d;
		int cnt = 0;
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] >='0' && s2[i]<='9') {
				int temp = s2[i] - '0';
				i++;
				while (s2[i] >= '0' && s2[i] <= '9') {
					temp *= 10;
					temp += s2[i] - '0';
					i++;
				}
				d.push_back(temp);
			}
		}
		int flag = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == 'R')cnt++;
			else {
				if (d.empty()) {
					flag = 1;
					break;
				}
				if (cnt % 2) {
					d.pop_back();
				}
				else {

					d.pop_front();
				}
			}
		}

		if (flag) {
			cout << "error\n";
		}
		else {
			cout << '[';
			if (cnt % 2) {
				for (int i = d.size() - 1; i >= 0; i--) {
					if (i != 0)cout << d[i] << ',';
					else cout << d[i];
				}
			}
			else {
				for (int i = 0; i < d.size(); i++) {
					if(i != d.size() - 1)cout << d[i] << ',';
					else cout<<d[i];
				}
			}
			cout << "]\n";
		}


	}



	return 0;
}
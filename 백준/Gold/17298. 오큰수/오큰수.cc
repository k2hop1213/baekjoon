#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<long long> a;
	list<long long> a1;
	stack<long long> a2;


	int n;
	cin >> n;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		a2.push(temp);
	}
	for (int i = 1; i <= n; i++) {
		long long temp = a2.top();
		a2.pop();
		if (i == 1) { 
			max = temp;
			a1.push_front(-1);
		}
		else {
			if (max > temp) {
				if (a.top() > temp) { 
					a1.push_front(a.top());
				}
				else {
					while (a.top() <= temp) {
						a.pop();
					}
					a1.push_front(a.top());
				}


			}
			else {
				a1.push_front(-1);
				max = temp;
			}
		}
		a.push(temp);
	}
	for (auto i : a1) {
		cout << i << " ";
	}

	return 0;
}
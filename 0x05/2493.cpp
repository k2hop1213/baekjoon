#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> a;
	stack<int> a1;

	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		if (i == 1) {
			cout << "0 ";
			max = temp;

		}
		else {
			if (max > temp) {
				if (a.top() > temp) {
					cout << a1.top() << " ";
				}
				else {
					while (a.top() < temp) {
						a.pop();
						a1.pop();
					}
					cout << a1.top() << " ";
				}


			}
			else {
				cout << "0 ";
				max = temp;
			}
		}
		a.push(temp);
		a1.push(i);
	}




	return 0;
}

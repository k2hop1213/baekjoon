#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int y = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		int temp1 = temp;
		while (temp > 0) {
			if (temp < 30) {
				y += 10;
				break;
			}
			else if (temp >= 30 && temp < 60) {
				y += 20;
				break;
			}
			y += 10;
			temp -= 30;
		}
		while (temp1 > 0) {
			if (temp1 < 60) {
				m += 15;
				break;
			}
			else if (temp1 >= 60 && temp1 < 120) {
				m += 30;
				break;
			}
			m += 15;
			temp1 -= 60;
		}

	}

	if (y == m) {
		cout << "Y M " << y;
	}
	else if (y < m) {
		cout << "Y " << y;
	}
	else {
		cout << "M " << m;
	}


	return 0;
}

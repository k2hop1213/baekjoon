#include <stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string n, m;
	cin >> n >> m;
	int cnt = 0;
	int res = 0;
	
	int len_n = n.length();
	int len_m = m.length();

	if (len_n != len_m) {
		cout << 0;
		return 0;
	}

	
	for (int i = 0; i < len_n; i++) {
		if (n[i] == '8' && m[i] == '8') {
			res++;
		}
		else if (n[i] != m[i]) {
			break;
		}
	}

	cout << res;
	return 0;
}

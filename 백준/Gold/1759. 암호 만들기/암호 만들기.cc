#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[20];
char s[20];
bool isused[20];
int cnt = 0;
int cnt1 = 0;
void func(int k, int start_idx) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				cnt++;
			}
			else cnt1++;
		}
		if (cnt < 1) {
			cnt = 0;
			return;
		}
		if (cnt1 < 2) {
			cnt1 = 0;
			return;
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << '\n';
		cnt = 0;
		cnt1 = 0;
		return;
	}
	for (int i = start_idx; i <= m; i++) {
		if (!isused[i]) {
			arr[k] = s[i];
			isused[i] = 1;
			func(k + 1, i + 1);
			isused[i] = 0;
		}
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + 1 + m);
	func(0, 1);

	return 0;
}
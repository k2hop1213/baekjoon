#include <stdc++.h>
using namespace std;

int arr[11];
int res[11];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) { 
		cin >> arr[i]; 
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0; 
		for (int j = 1; j <= n; j++) {
			if (res[j] == 0) {
				if (cnt == arr[i]) {
					res[j] = i; 
					break;
				}
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << res[i] << ' ';

	return 0;
}

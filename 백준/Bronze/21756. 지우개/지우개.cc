#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	int size = n;

	while (size > 1) {
		int idx = 1;
		for (int i = 1; i <= size; i = i + 2) {
			arr[i] = 0;
		}
		for (int i = 2; i <= size; i = i + 2) {
			arr[idx] = arr[i];
			idx++;
		}
		size /= 2;
	}

	cout << arr[1];
	

	return 0;
}
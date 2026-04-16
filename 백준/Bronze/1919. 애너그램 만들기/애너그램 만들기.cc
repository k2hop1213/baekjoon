#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	string s1;
	string s2;
	cin >> s1 >> s2;
	for (auto a : s1) {
		arr1[a - 'a']++;
	}
	for (auto a : s2) {
		arr2[a - 'a']++;
	}
	int res = 0;

	for (int i = 0; i < 26; i++) {
		if ((arr1[i] > 0)^(arr2[i]>0)) {
			int temp = (arr1[i] > 0) ? arr1[i] : arr2[i];
			res += temp;
		}
		else if (arr1[i] && arr2[i]) {
			int temp = (arr1[i] > arr2[i]) ? arr1[i] - arr2[i] : arr2[i] - arr1[i];
			res += temp;
		}
	}
	cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[2001];
int dp[2002][2002];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}

	for (int i = n; i >= 1; i--) {
	    for (int j = i; j <= n; j++) {
		    if (arr[i] == arr[j]) {
			    if (j - i < 2) dp[i][j] = 1;
			    else if (dp[i + 1][j - 1] == 1) dp[i][j] = 1;
		    }

	    }
    }

	int m;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}




	return 0;
}
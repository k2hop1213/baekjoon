#include <bits/stdc++.h>
using namespace std;

int arr[1001];
pair<int, int> arr1[21];
int vis[1002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> arr[i];
	int idx = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (idx < n) { //처음 걸리는 사람
			if (vis[arr[i]] == 0) {
				arr1[idx].first = arr[i];
				arr1[idx].second = cnt;
				idx++; cnt++;
			}
			vis[arr[i]]++; // 이전에 추천받았으면 추천수만 올라감
			
		}
		else if(idx == n && vis[arr[i]] == 0) {
			
			int min_idx = vis[arr1[0].first];
			int min_cnt = 0;
			for (int j = 0; j < n; j++) {
				min_idx = min(min_idx, vis[arr1[j].first]);
			}
			for (int j = 0; j < n; j++) {
				if (vis[arr1[j].first] == min_idx) {
					min_cnt++;
					idx = j;
				}
			}
			if (min_cnt > 1) {
				int temp = cnt;
				for (int j = 0; j < n; j++) {
					
					if (vis[arr1[j].first] == min_idx) {
						temp = min(temp, arr1[j].second);
						if (temp == arr1[j].second) {
							idx = j;
						}
					}

				}
			}
			vis[arr1[idx].first] = 0;
			arr1[idx].first = arr[i];
			arr1[idx].second = cnt;
			vis[arr[i]]++;
			cnt++;
			idx = n;
		}
		else if (vis[arr[i]]) {
			vis[arr[i]]++;
		}
	}
	sort(arr1, arr1 + n);
	for (int i = 0; i < n; i++) {
		if (arr1[i].first == 0)continue;
		cout << arr1[i].first << ' ';
	}


	return 0;
}
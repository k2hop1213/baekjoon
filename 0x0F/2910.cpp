#include <stdc++.h>
using namespace std;

pair<int, int> cnt[1001];//빈도, 변수 값
int arr[1001];
bool vis[1001];

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second; 
	return a.first > b.first; 
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		cnt[idx].second = i;
		cnt[idx].first = 1;
		vis[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				cnt[idx].first++;
				vis[j] = 1;
			}
		}
		idx++;
	}
	sort(cnt, cnt + idx, compare);

	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < cnt[i].first; j++) {
			cout << arr[cnt[i].second] << ' ';
		}

	}

	

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

// 전역 배열 대신 vector를 사용했습니다. (권장 사항)
// int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, L;
	cin >> n >> w >> L;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	// 큐를 <무게, 다리에서 완전히 나가는 시간>으로 정의합니다.
	queue<pair<int, int>> Q;

	int res = 0;            // 경과 시간 (0부터 시작)
	int current_weight = 0; // 현재 다리 위에 있는 트럭들의 총 무게 (사용자님의 sum 역할)
	int next_truck_idx = 0; // 다음에 다리에 진입할 트럭의 인덱스 (사용자님의 idx 역할)

	// 모든 트럭이 진입하고 다리가 완전히 비워질 때까지 반복
	while (next_truck_idx < n || !Q.empty()) {

		// 1. 시간 1 증가 (매 턴 무조건 실행)
		res++;

		// 2. 트럭 퇴장 처리 (시간이 되어 다리를 완전히 건넌 트럭 처리)
		// 현재 시간(res)이 Q.front().second (퇴장 시간)과 같아지면 퇴장
		if (!Q.empty() && Q.front().second == res) {
			current_weight -= Q.front().first; // 총 무게에서 뺌
			Q.pop(); // 트럭 퇴장
		}

		// 3. 새 트럭 진입 시도 (아직 진입할 트럭이 남아있다면)
		if (next_truck_idx < n) {
			int next_truck_weight = arr[next_truck_idx];

			// 진입 조건: 현재 총 무게 + 다음 트럭 무게 <= 최대 하중 L
			if (current_weight + next_truck_weight <= L) {
				// 트럭 진입: 큐에 {무게, 현재 시간 + 다리 길이}를 넣어 퇴장 시간을 계산
				Q.push({ next_truck_weight, res + w });
				current_weight += next_truck_weight; // 총 무게 업데이트
				next_truck_idx++; // 다음 트럭 준비
			}
			// else: 하중 초과 시, 새 트럭은 진입하지 않고 다음 턴을 기다립니다.
		}
	}

	cout << res;
	return 0;
}
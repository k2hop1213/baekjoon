#include <bits/stdc++.h>
using namespace std;
int board[100001];
int vis[100002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;
	for (int t = 0; t < a; t++) {
		fill(board, board + 100001, -1);
		fill(vis, vis + 100002, 0);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			board[i] = temp - 1;
		}
		int team_members = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i] != 0) {
				continue; // 이미 처리된 학생은 건너뜁니다.
			}

			stack<int> S;
			S.push(i); // 현재 학생을 스택에 넣고 탐색 시작

			while (!S.empty()) {
				int current = S.top();

				if (vis[current] == 0) {
					// 1. 처음 방문하는 경우: '탐색 중' 상태로 변경
					vis[current] = 1;

					int next = board[current];

					if (vis[next] == 0) {
						// 다음 노드가 미방문이면, 다음 탐색을 위해 스택에 추가
						S.push(next);
					}
					else {
						// 다음 노드가 이미 방문된 경우 (사이클 발견 또는 경로 종료)

						if (vis[next] == 1) {
							// Case: next가 '탐색 중'이면 **사이클 발견!**
							int cycle_start = next;
							int cycle_count = 0;

							// 사이클 카운트 및 상태 업데이트
							int runner = cycle_start;
							do {
								// 사이클 멤버는 팀원 확정 (상태 2)
								vis[runner] = 2;
								runner = board[runner];
								cycle_count++;
							} while (runner != cycle_start);

							team_members += cycle_count;
						}
						// Case: vis[next] == 2 이면, 이미 처리된 경로이므로 현재 노드는 미팀원.

						// 현재 노드 처리가 완료되었으므로 '탐색 완료'로 설정하고 스택에서 제거
						// 사이클에 진입하는 경로상의 노드도 여기서 2로 처리됩니다.
						vis[current] = 2;
						S.pop();
					}

				}
				else if (vis[current] == 1) {
					// 2. 백트래킹 지점: '탐색 중' 상태에서 다시 돌아옴
					// 이 노드는 사이클 진입 경로에 있었거나 사이클의 일부였지만 이미 처리가 완료됨.
					// '탐색 완료' 상태로 변경하고 스택에서 제거
					vis[current] = 2;
					S.pop();
				}
				else { // vis[current] == 2
					// 3. 이미 처리 완료된 노드 (스택에 남아있는 경우)
					S.pop();
				}
			}
		}

		// 최종 결과: 전체 학생 수 N - 팀에 속한 학생 수 team_members
		cout << n - team_members << "\n";
	}


	
}
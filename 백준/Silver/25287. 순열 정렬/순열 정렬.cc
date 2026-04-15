#include <iostream>
#include <algorithm> // min, max 함수 사용

using namespace std;

int arr[50001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];

        // 1. 초기값 설정: 이전 숫자를 아주 작은 값으로 시작
        int last_value = 0;
        int flag = 0;

        for (int i = 1; i <= n; i++) {
            // 연산을 안 했을 때의 값과 했을 때의 값 두 가지 후보가 있음
            int v1 = arr[i];
            int v2 = n - arr[i] + 1;

            // 두 값 중 작은 값과 큰 값을 구분
            int small = min(v1, v2);
            int large = max(v1, v2);

            // 2. 그리디(Greedy) 선택
            // 최대한 작은 값을 선택해야 다음 숫자가 들어올 공간이 넓어짐
            if (small >= last_value) {
                last_value = small;
            } 
            // 작은 값이 안 되면 큰 값이라도 선택 (이것도 안 되면 실패)
            else if (large >= last_value) {
                last_value = large;
            } 
            else {
                flag = 1; // 감소하지 않는 수열을 만들 수 없는 경우
                break;
            }
        }

        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}